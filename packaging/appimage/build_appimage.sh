#!/usr/bin/env bash
# Build Monitor GPU as a portable AppImage (Ubuntu 22.04+ / x86_64).
#
# Usage:
#   ./packaging/appimage/build_appimage.sh
#
# Output:
#   packaging/appimage/dist/MonitorGPU-x86_64.AppImage

set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
PKG_DIR="${ROOT}/packaging/appimage"
BUILD_DIR="${PKG_DIR}/build"
DIST_DIR="${PKG_DIR}/dist"
VENV_DIR="${BUILD_DIR}/conda-env"
APPDIR="${BUILD_DIR}/MonitorGPU.AppDir"
ARCH="$(uname -m)"
VERSION="0.1.0"
APPIMAGE_NAME="MonitorGPU-${ARCH}.AppImage"

echo "==> Project root: ${ROOT}"
echo "==> Architecture: ${ARCH}"

if [[ "${ARCH}" != "x86_64" && "${ARCH}" != "aarch64" ]]; then
    echo "Unsupported architecture: ${ARCH}" >&2
    exit 1
fi

mkdir -p "${BUILD_DIR}" "${DIST_DIR}"

PYTHON="python3"
PIP=(python3 -m pip)

setup_build_env() {
    if [[ -x "${VENV_DIR}/bin/python" ]]; then
        PYTHON="${VENV_DIR}/bin/python"
        PIP=("${PYTHON}" -m pip)
        return 0
    fi

    echo "==> Creating build virtualenv..."
    rm -rf "${VENV_DIR}"
    if python3 -c "import ensurepip" 2>/dev/null && python3 -m venv "${VENV_DIR}" 2>/dev/null; then
        PYTHON="${VENV_DIR}/bin/python"
        PIP=("${PYTHON}" -m pip)
        return 0
    fi

    if command -v mamba >/dev/null 2>&1; then
        echo "==> venv unavailable; using mamba env at ${VENV_DIR}"
        rm -rf "${VENV_DIR}"
        mamba create -y -p "${VENV_DIR}" python=3.10 pip tk
        # shellcheck disable=SC1091
        eval "$(conda shell.bash hook)"
        conda activate "${VENV_DIR}"
        PYTHON="${VENV_DIR}/bin/python"
        PIP=("${PYTHON}" -m pip)
        return 0
    fi

    if command -v conda >/dev/null 2>&1; then
        echo "==> venv unavailable; using conda env at ${VENV_DIR}"
        rm -rf "${VENV_DIR}"
        conda create -y -p "${VENV_DIR}" python=3.10 pip tk
        # shellcheck disable=SC1091
        eval "$(conda shell.bash hook)"
        conda activate "${VENV_DIR}"
        PYTHON="${VENV_DIR}/bin/python"
        PIP=("${PYTHON}" -m pip)
        return 0
    fi

    echo "ERROR: cannot create a build environment." >&2
    echo "Install one of:" >&2
    echo "  sudo apt install python3.10-venv python3-tk" >&2
    echo "  miniforge / mamba (conda)" >&2
    exit 1
}

setup_build_env

echo "==> Installing build dependencies..."
"${PIP[@]}" install --upgrade pip wheel
"${PIP[@]}" install -r "${PKG_DIR}/requirements-build.txt"

if ! "${PYTHON}" -c "import tkinter" 2>/dev/null; then
    echo "ERROR: python3-tk is required. Install it with:" >&2
    echo "  sudo apt install python3-tk" >&2
    exit 1
fi

echo "==> Running PyInstaller..."
# Avoid picking up unrelated packages from PYTHONPATH during analysis.
env -u PYTHONPATH "${PYTHON}" -m PyInstaller \
    --noconfirm \
    --clean \
    --distpath "${BUILD_DIR}/pyinstaller-dist" \
    --workpath "${BUILD_DIR}/pyinstaller-work" \
    "${PKG_DIR}/monitor-gpu.spec"

PYINSTALLER_OUT="${BUILD_DIR}/pyinstaller-dist/monitor-gpu"
if [[ ! -x "${PYINSTALLER_OUT}/monitor-gpu" ]]; then
    echo "PyInstaller output not found at ${PYINSTALLER_OUT}/monitor-gpu" >&2
    exit 1
fi

APPIMAGETOOL="${BUILD_DIR}/appimagetool-${ARCH}.AppImage"
if [[ ! -x "${APPIMAGETOOL}" ]]; then
    echo "==> Downloading appimagetool..."
    APPIMAGETOOL_URL="https://github.com/AppImage/AppImageKit/releases/download/continuous/appimagetool-${ARCH}.AppImage"
    curl -fsSL -o "${APPIMAGETOOL}" "${APPIMAGETOOL_URL}"
    chmod +x "${APPIMAGETOOL}"
fi

echo "==> Assembling AppDir..."
rm -rf "${APPDIR}"
mkdir -p "${APPDIR}/usr/bin"

cp -a "${PYINSTALLER_OUT}" "${APPDIR}/usr/bin/monitor-gpu"
cp "${PKG_DIR}/monitor-gpu.desktop" "${APPDIR}/"
cp "${PKG_DIR}/monitor-gpu.svg" "${APPDIR}/monitor-gpu.svg"

if [[ -f "${PKG_DIR}/monitor-gpu.png" ]]; then
    cp "${PKG_DIR}/monitor-gpu.png" "${APPDIR}/monitor-gpu.png"
elif command -v convert >/dev/null 2>&1; then
    convert -background none "${PKG_DIR}/monitor-gpu.svg" \
        "${APPDIR}/monitor-gpu.png"
elif [[ -x "${VENV_DIR}/bin/python" ]] || command -v python3 >/dev/null 2>&1; then
    ICON_PY="${PYTHON:-python3}"
    "${ICON_PY}" "${PKG_DIR}/generate_icon.py"
    cp "${PKG_DIR}/monitor-gpu.png" "${APPDIR}/monitor-gpu.png"
else
    echo "ERROR: monitor-gpu.png missing and cannot generate one." >&2
    exit 1
fi

cat > "${APPDIR}/AppRun" <<'EOF'
#!/bin/bash
set -e
SELF="$(readlink -f "$0")"
HERE="${SELF%/*}"
export APPDIR="${HERE}"
export PATH="${APPDIR}/usr/bin:${PATH}"
export LD_LIBRARY_PATH="${APPDIR}/usr/bin/monitor-gpu:${LD_LIBRARY_PATH:-}"
export MPLBACKEND=TkAgg
export MPLCONFIGDIR="${XDG_CACHE_HOME:-${HOME}/.cache}/monitor-gpu/mpl"
mkdir -p "${MPLCONFIGDIR}"
exec "${APPDIR}/usr/bin/monitor-gpu/monitor-gpu" "$@"
EOF
chmod +x "${APPDIR}/AppRun"

cat > "${APPDIR}/usr/bin/monitor-gpu-wrapper" <<'EOF'
#!/bin/bash
exec monitor-gpu/monitor-gpu "$@"
EOF
chmod +x "${APPDIR}/usr/bin/monitor-gpu-wrapper"

echo "==> Building AppImage..."
export ARCH
OUTPUT="${DIST_DIR}/${APPIMAGE_NAME}"
ARCH="${ARCH}" "${APPIMAGETOOL}" "${APPDIR}" "${OUTPUT}"

chmod +x "${OUTPUT}"
echo ""
echo "Done: ${OUTPUT}"
echo "Run with:"
echo "  ${OUTPUT}"
echo "Or copy to another Linux machine (same CPU arch) and:"
echo "  chmod +x MonitorGPU-${ARCH}.AppImage"
echo "  ./MonitorGPU-${ARCH}.AppImage"

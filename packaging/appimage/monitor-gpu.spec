# -*- mode: python ; coding: utf-8 -*-
"""PyInstaller spec for Monitor GPU AppImage."""

from pathlib import Path

from PyInstaller.utils.hooks import collect_all, collect_data_files

block_cipher = None

project_root = Path(SPECPATH).resolve().parent.parent
script = project_root / "utils" / "monitor_gpu.py"
rthook = Path(SPECPATH).resolve() / "rthook_pil_tk.py"

datas = collect_data_files("matplotlib")
pil_datas, pil_binaries, pil_hidden = collect_all("PIL")
datas += pil_datas

a = Analysis(
    [str(script)],
    pathex=[str(project_root)],
    binaries=pil_binaries,
    datas=datas,
    hiddenimports=[
        "matplotlib.backends.backend_tkagg",
        "PIL._imagingtk",
        "PIL._tkinter_finder",
        "PIL.ImageTk",
        "pynvml",
        "psutil",
        *pil_hidden,
    ],
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[str(rthook)],
    excludes=[],
    win_no_prefer_redirects=False,
    win_private_assemblies=False,
    cipher=block_cipher,
    noarchive=False,
)

pyz = PYZ(a.pure, a.zipped_data, cipher=block_cipher)

exe = EXE(
    pyz,
    a.scripts,
    [],
    exclude_binaries=True,
    name="monitor-gpu",
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    console=False,
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
)

coll = COLLECT(
    exe,
    a.binaries,
    a.zipfiles,
    a.datas,
    strip=False,
    upx=True,
    upx_exclude=[],
    name="monitor-gpu",
)

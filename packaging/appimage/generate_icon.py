#!/usr/bin/env python3
"""Generate packaging/appimage/monitor-gpu.png from the SVG design."""

from pathlib import Path

from PIL import Image, ImageDraw

ROOT = Path(__file__).resolve().parent
OUT = ROOT / "monitor-gpu.png"


def main() -> None:
    size = 256
    img = Image.new("RGBA", (size, size), (30, 39, 46, 255))

    panels = [
        ((28, 36, 120, 108), (15, 188, 249, 64), [(40, 88), (58, 72), (76, 78), (94, 52)]),
        ((136, 36, 228, 108), (255, 192, 72, 64), [(148, 88), (166, 64), (184, 70), (202, 48)]),
        ((28, 148, 120, 220), (5, 196, 107, 64), [(40, 200), (58, 184), (76, 188), (94, 168)]),
        ((136, 148, 228, 220), (87, 95, 207, 64), [(148, 200), (166, 176), (184, 182), (202, 160)]),
    ]

    for box, fill, line in panels:
        overlay = Image.new("RGBA", (size, size), (0, 0, 0, 0))
        ImageDraw.Draw(overlay).rounded_rectangle(box, radius=8, fill=fill)
        img = Image.alpha_composite(img, overlay)
        ImageDraw.Draw(img).line(line, fill=fill[:3], width=6, joint="curve")

    img.save(OUT)
    print(f"Wrote {OUT}")


if __name__ == "__main__":
    main()

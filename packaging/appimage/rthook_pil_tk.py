"""Pre-load Pillow Tk glue before matplotlib creates its Tk window."""

import sys


def _preload_pil_tk() -> None:
    if not getattr(sys, "frozen", False):
        return
    for module in ("PIL._imagingtk", "PIL._tkinter_finder", "PIL.ImageTk"):
        try:
            __import__(module)
        except ImportError:
            pass


_preload_pil_tk()

import time

import viser


def main():
    server = viser.ViserServer()
    server.scene.add_icosphere(
        name="/hello_sphere",
        radius=0.5,
        color=(255, 0, 0),  # Red
        position=(0.0, 0.0, 0.0),
    )

    print("Open your browser to http://localhost:8080")
    print("Press Ctrl+C to exit")

    while True:
        time.sleep(10.0)


if __name__ == "__main__":
    main()
    
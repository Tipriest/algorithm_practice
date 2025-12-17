import time
import numpy as np
import viser


def main() -> None:
    server = viser.ViserServer()

    # Line Segments
    #
    # This will be much faster than creating separate scene
    # objects for individual line segments or splines
    N = 1
    points = np.random.normal(size=(N, 2, 3)) * 3.0
    colors = np.random.randint(0, 255, size=(N, 2, 3))

    server.scene.add_line_segments(
        "/line_segments",
        points=points,
        colors=colors,
        line_width=3.0,
    )

    # Spline helpers
    #
    # If many lines are needed, it'll be more efficient to batch
    # them in `add_line_segments()`.
    for i in range(0):
        points = np.random.normal(size=(10, 3)) * 3.0
        server.scene.add_point_cloud(
            f"/catmull_pcl/{i}",
            points=points,
            colors=np.random.uniform(size=3),
            point_size=0.3,
            point_shape="rounded",
        )

        server.scene.add_spline_catmull_rom(
            f"/catmull/{i}",
            points=points,
            tension=0.5,
            line_width=3.0,
            color=np.random.uniform(size=3),
            segments=100,
        )

    for i in range(1):
        points = np.random.normal(size=(5, 3)) * 3.0
        control_points = np.random.normal(size=(5 * 2 - 2, 3)) * 3.0
        server.scene.add_point_cloud(
            f"/cubic_bezier_points/{i}",
            points=points,
            colors=np.random.uniform(size=3),
            point_size=0.3,
            point_shape="rounded",
        )
        server.scene.add_point_cloud(
            f"/cubic_bezier_control_points/{i}",
            points=control_points,
            colors=np.random.uniform(size=3),
            point_size=0.3,
            point_shape="square",
        )
        server.scene.add_spline_cubic_bezier(
            f"/cubic_bezier/{i}",
            points=points,
            control_points=control_points,
            line_width=3.0,
            color=np.random.uniform(size=3),
            segments=100,
        )

    while True:
        time.sleep(10.0)


if __name__ == "__main__":
    main()

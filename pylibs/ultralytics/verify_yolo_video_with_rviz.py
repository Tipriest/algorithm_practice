#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import time
from pathlib import Path

import cv2
import numpy as np
from tqdm import tqdm  # 进度条

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

from ultralytics import YOLO


# 你给的颜色表：key 是类别 id 字符串，值是 [R,G,B]，范围 0~1
COLOR_MAP = {
    "0": [0.7294974719490496, 0.252436464369557, 0.5680995585582647],
    "1": [0.26224306872547035, 0.8019770623777137, 0.1618809902449637],
    "2": [0.38250310304259806, 0.01878197299081757, 0.02163594269126263],
    "3": [0.7040137886991669, 0.07888157705257587, 0.002229534625824027],
    "4": [0.23399102752067733, 0.6154296525080703, 0.7404304262282372],
    "5": [0.7765805886253542, 0.17086898340438612, 0.7580807663707406],
    "6": [0.9891092218301167, 0.7766424842358539, 0.09150273970640324],
    "7": [0.3167896388454274, 0.3686168752927701, 0.38113745564296905],
    "8": [0.218740896628122, 0.8015833256056708, 0.5127894316815646],
    "9": [0.360767676477867, 0.6650990518428578, 0.03642717314407309],
    "10": [0.5417683688912549, 0.979893164329724, 0.7581393912152399],
    "11": [0.6540872900733984, 0.8852351591425769, 0.7419794378596019],
    "12": [0.1933795962283576, 0.4690009790365929, 0.3002163689148202],
    "13": [0.68275596989484, 0.174718312528732, 0.6248570908606822],
    "14": [0.3373099139564776, 0.3046122321576532, 0.7431032418208702],
    "15": [0.8898064735965234, 0.42156738489988044, 0.3820883789897177],
    "16": [0.8234441101449561, 0.9701181787739911, 0.1302760482347411],
    "17": [0.11864881583571134, 0.08962308286337864, 0.7709859675485553],
    "18": [0.22742077863838484, 0.6394531787196488, 0.9957209330093717],
    "19": [0.08091747826781742, 0.5728056054985421, 0.979694138466046],
    "20": [0.8948268975468658, 0.4874851101429557, 0.46057071484260197],
    "21": [0.34920052884603025, 0.3082001961400475, 0.12436937510567683],
    "22": [0.5103847425560712, 0.4526894617913856, 0.0016495614166282134],
    "23": [0.9951011465074772, 0.4389445519043317, 0.04153525459664319],
    "24": [0.010799567319042304, 0.9742744388778173, 0.3530456441548053],
    "25": [0.7770962324729713, 0.9491710142972366, 0.8596252042378033],
    "26": [0.3192286148787947, 0.7807807501330184, 0.20349171574691323],
    "27": [0.9546983258811628, 0.3761023533665795, 0.28690837969495647],
    "28": [0.08336360987795596, 0.20246398940225928, 0.9625708241374445],
    "29": [0.5090830036587887, 0.7467545001918615, 0.4582547204200419],
    "30": [0.9605669568703452, 0.28579940152475325, 0.7263806179975154],
    "31": [0.4941992923083538, 0.05834310963627731, 0.6710516399058895],
    "32": [0.5999229813368133, 0.14038419352769216, 0.1961632383244739],
    "33": [0.41102554443077866, 0.2687559781881381, 0.4427659899571158],
    "34": [0.6950014871118952, 0.4918711749671444, 0.8725355935704955],
    "35": [0.19021672443940962, 0.9842339660243428, 0.9376141348119362],
    "36": [0.16286767514185918, 0.3767007390138415, 0.9088666374945361],
    "37": [0.9086151655040376, 0.5544459101994034, 0.2874340137688455],
    "38": [0.8583133889049183, 0.6936676822370683, 0.32442420938537975],
    "39": [0.8447328282090601, 0.8420300768073546, 0.9571566057741043],
    "40": [0.7838708104944018, 0.7170661422775024, 0.23270248186496933],
    "41": [0.31984337784429306, 0.8041747197668614, 0.1469047283679622],
    "42": [0.6921220728050077, 0.2691783680039733, 0.8403217280217289],
    "43": [0.26156841766563277, 0.0833691547546267, 0.02168754161187636],
    "44": [0.22247836388623976, 0.8342176153438225, 0.7867646138202542],
    "45": [0.8523846438549557, 0.04841903490779931, 0.6788795640518682],
    "46": [0.6871590906352144, 0.5488451510883626, 0.07235855717477613],
    "47": [0.39548106470019795, 0.007340011151790948, 0.021458333808965446],
    "48": [0.7134815811469496, 0.489257696387698, 0.8118167488896564],
    "49": [0.3854171821494672, 0.48941345363667754, 0.7877367589391817],
    "50": [0.6758386068889752, 0.7653289906168188, 0.9246592232714832],
    "51": [0.21319628538136404, 0.1072438575964304, 0.6934732010785266],
    "52": [0.06651286659292832, 0.18323317724883714, 0.0038146436359496327],
    "53": [0.36997280704708546, 0.9432960429485308, 0.03432625360305519],
    "54": [0.24915975677176128, 0.9386229294676685, 0.10673158346845646],
    "55": [
        0.11541869793632487,
        4267949,
        0.8176492972233009,
    ],  # 这一行有问题, 建议改成 0~1
    "80": [0.13734981446286865, 0.9392306517543818, 0.6937140444086529],
    "81": [0.3087905552061744, 0.5658756684718073, 0.09026476069109124],
    "82": [0.19255434895633994, 0.9101982610244425, 0.18692411270477927],
    "83": [0.5269893484976009, 0.22052111151481568, 0.7950715291202938],
    "84": [0.016838587591263, 0.45015918285308243, 0.9834992759037708],
    "85": [0.7427613637320684, 0.6641472750255167, 0.5322501714016216],
    "86": [0.21445668004118656, 0.13868632772451828, 0.5466537507842003],
    "87": [0.24348078834757036, 0.44811528903990716, 0.2474672318375447],
    "88": [0.5638560954632338, 0.8154168113505038, 0.1358617865203685],
}


class YoloRos2Subscriber(Node):
    def __init__(
        self,
        model_path: str,
        class_labels_path: str = None,
        video_output_path: str = "output.mp4",
        msg_timeout: float = 15.0,
        fps: int = 30,
    ):
        super().__init__("yolo_ros2_subscriber")

        self.bridge = CvBridge()

        # 订阅原始图像
        self.subscription = self.create_subscription(
            Image,
            "/camera/color/image_raw",
            self.image_callback,
            10,
        )

        # 新增：发布带框后的图像
        self.image_pub = self.create_publisher(
            Image, "/yolo/image_annotated", 10
        )

        self.initialized = False
        self.model_path = model_path
        self.class_labels_path = class_labels_path
        self.model = None
        self.class_names = None

        self.video_output_path = video_output_path
        self.video_writer = None
        self.frame_size = None
        self.fps = fps

        self.msg_timeout = msg_timeout
        self.last_msg_time = None

        self.frame_count = 0
        # self.estimated_max_frames = int(self.msg_timeout * self.fps)
        self.estimated_max_frames = 2545
        self.pbar = tqdm(
            total=self.estimated_max_frames,
            bar_format="Saving video |{bar}| {n_fmt}/{total_fmt} frames",
            file=sys.stdout,
        )

        self.timer = self.create_timer(1.0, self.check_timeout)

        self.get_logger().info(
            "Node init done, waiting for first frame on /camera/color/image_raw ..."
        )

    def _lazy_initialize(self, cv_image):
        self.get_logger().info(f"Loading YOLO model from: {self.model_path}")
        self.model = YOLO(self.model_path)

        if (
            self.class_labels_path is not None
            and Path(self.class_labels_path).is_file()
        ):
            self.get_logger().info(
                f"Loading class labels from: {self.class_labels_path}"
            )
            with open(self.class_labels_path, "r", encoding="utf-8") as f:
                self.class_names = [line.strip() for line in f if line.strip()]
        else:
            self.class_names = self.model.names

        self.frame_size = (cv_image.shape[1], cv_image.shape[0])
        fourcc = cv2.VideoWriter_fourcc(*"mp4v")
        self.video_writer = cv2.VideoWriter(
            self.video_output_path,
            fourcc,
            self.fps,
            self.frame_size,
        )

        if not self.video_writer.isOpened():
            self.get_logger().error(
                f"Failed to open VideoWriter for {self.video_output_path}"
            )
        else:
            self.get_logger().info(
                f"VideoWriter initialized: {self.video_output_path}, "
                f"size={self.frame_size}, fps={self.fps}"
            )

        self.initialized = True
        self.get_logger().info(
            "First frame received, YOLO and video initialized."
        )

    def image_callback(self, msg: Image):
        self.last_msg_time = time.time()

        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        except Exception as e:
            self.get_logger().error(f"cv_bridge error: {e}")
            return

        # 上下+左右翻转
        cv_image = cv2.flip(cv_image, 0)
        cv_image = cv2.flip(cv_image, 1)

        if not self.initialized:
            self._lazy_initialize(cv_image)

        if self.model is None:
            return

        # 目标检测推理
        results = self.model(cv_image, verbose=False)
        if len(results) > 0:
            result = results[0]
            boxes = result.boxes

            if boxes is not None and len(boxes) > 0:
                for box in boxes:
                    x1, y1, x2, y2 = box.xyxy[0].cpu().numpy().astype(int)

                    conf = float(box.conf[0].cpu().numpy())
                    cls_id = int(box.cls[0].cpu().numpy())
                    print(
                        f"x1: {x1}, y1: {y1}, x2: {x2}, y2: {y2}, conf: {conf}, cls_id: {cls_id}"
                    )

                    # 取类别名
                    if self.class_names and 0 <= cls_id < len(self.class_names):
                        label = self.class_names[cls_id]
                    else:
                        label = str(cls_id)

                    text = f"{label} {conf:.2f}"

                    # 根据类别 id 取颜色
                    key = str(cls_id)
                    if key in COLOR_MAP:
                        r, g, b = COLOR_MAP[key]  # 0~1 RGB
                        color = (
                            int(b * 255),
                            int(g * 255),
                            int(r * 255),
                        )
                    else:
                        color = (0, 255, 0)  # 默认绿色

                    cv2.rectangle(cv_image, (x1, y1), (x2, y2), color, 2)
                    cv2.putText(
                        cv_image,
                        text,
                        (x1, max(0, y1 - 5)),
                        cv2.FONT_HERSHEY_SIMPLEX,
                        0.6,
                        color,
                        2,
                        cv2.LINE_AA,
                    )

        # 写入视频
        if self.video_writer is not None and self.video_writer.isOpened():
            self.video_writer.write(cv_image)
            self.frame_count += 1
            if self.frame_count > self.pbar.total:
                self.pbar.total = self.frame_count
            # self.pbar.update(1)

        # ==== 新增：发布带框后的图像到 ROS2 ====
        try:
            annotated_msg = self.bridge.cv2_to_imgmsg(cv_image, encoding="bgr8")
            annotated_msg.header = msg.header  # 继承时间戳和 frame_id
            self.image_pub.publish(annotated_msg)
        except Exception as e:
            self.get_logger().error(f"Failed to publish annotated image: {e}")
        # =====================================

    def check_timeout(self):
        if self.last_msg_time is not None:
            elapsed = time.time() - self.last_msg_time
            if elapsed > self.msg_timeout:
                self.get_logger().info(
                    f"No image messages for {elapsed:.1f}s (> {self.msg_timeout}s). "
                    "Saving video and shutting down."
                )
                self.cleanup()
                rclpy.shutdown()

    def cleanup(self):
        if self.pbar is not None:
            if self.frame_count < self.pbar.total:
                # self.pbar.update(self.pbar.total - self.frame_count)
                pass
            self.pbar.close()

        if self.video_writer is not None:
            try:
                self.video_writer.release()
                self.get_logger().info(
                    f"Video saved to: {self.video_output_path}, "
                    f"total frames: {self.frame_count}"
                )
            except Exception as e:
                self.get_logger().error(f"Error releasing VideoWriter: {e}")
            finally:
                self.video_writer = None


def main():
    try:
        import numpy
        import cv2 as _cv2

        print("Python executable:", sys.executable)
        print("NumPy version:", numpy.__version__)
        print("OpenCV version:", _cv2.__version__)
    except Exception:
        pass

    rclpy.init()

    model_path = "/home/tipriest/Downloads/yolo_results/last.pt"
    class_labels_path = "/home/tipriest/Documents/algorithm_practice/pylibs/ultralytics/self_trained.txt"

    node = YoloRos2Subscriber(
        model_path=model_path,
        class_labels_path=class_labels_path,
        video_output_path=f"/home/tipriest/Videos/output_{time.time()}.mp4",
        msg_timeout=5.0,
        fps=5,
    )

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("KeyboardInterrupt, shutting down.")
    finally:
        node.cleanup()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()

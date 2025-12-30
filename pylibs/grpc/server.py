import grpc
from concurrent import futures
import time

import helloworld_pb2
import helloworld_pb2_grpc


# 实现 Greeter 服务
class Greeter(helloworld_pb2_grpc.GreeterServicer):
    def SayHello(self, request, context):
        # request 是 HelloRequest 类型
        name = request.name
        reply_message = f"Hello, {name}! This is gRPC server on Ubuntu 22."
        return helloworld_pb2.HelloReply(message=reply_message)


def serve():
    # 创建 gRPC 服务器对象
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))

    # 将我们实现的 Greeter 服务添加到服务器
    helloworld_pb2_grpc.add_GreeterServicer_to_server(Greeter(), server)

    # 监听所有网卡（0.0.0.0）的 50051 端口
    server.add_insecure_port('[::]:50051')

    # 启动服务器
    server.start()
    print("gRPC server started, listening on port 50051 ...")

    try:
        while True:
            time.sleep(86400)  # 一直挂起
    except KeyboardInterrupt:
        print("Stopping gRPC server ...")
        server.stop(0)


if __name__ == '__main__':
    serve()

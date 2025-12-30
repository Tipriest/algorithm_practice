import grpc

import helloworld_pb2
import helloworld_pb2_grpc


def run():
    # 把下面的 IP 改为 Ubuntu 22 服务器在局域网中的 IP 地址
    # 比如 192.168.1.100 之类的
    server_ip = "192.168.2.103"
    server_port = 50051

    target = f"{server_ip}:{server_port}"

    # 建立到服务器的通道（未加密的）
    with grpc.insecure_channel(target) as channel:
        # 通过通道创建 Stub（客户端对象）
        stub = helloworld_pb2_grpc.GreeterStub(channel)

        # 构造请求消息
        request = helloworld_pb2.HelloRequest(name="Ubuntu 20 Client")

        # 调用远程方法 SayHello
        try:
            response = stub.SayHello(request, timeout=3)  # 设置 3 秒超时
            print("Received from server:", response.message)
        except grpc.RpcError as e:
            print("gRPC call failed:")
            print("  code   :", e.code())
            print("  details:", e.details())


if __name__ == '__main__':
    run()

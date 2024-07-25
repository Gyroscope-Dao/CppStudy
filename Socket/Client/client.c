#include"../tcpSocket/tcpSocket.h"

int main() {

	init_Socket();

	SOCKET fd = createClientSocket("127.0.0.1");
	char sendbuf[BUFSIZ] = "你好，我是客户端QAQ";
	char recvbuf[BUFSIZ] = { 0 };

	while (true) {
		//发送消息
		printf("send>");
		gets_s(sendbuf, BUFSIZ);
		if (SOCKET_ERROR == send(fd, sendbuf, strlen(sendbuf), 0)) {//失败
			err("send");
		}

		//recv从指定的socket接受信息
		if (0 < recv(fd, recvbuf, BUFSIZ, 0)) {//成功
			printf("recv:%s\n", recvbuf);
			memset(sendbuf, 0, sizeof(sendbuf));//内存清空
		}
	}

	closesocket(fd);
	close_Socket();
	printf("client-----end-----\n");
	getchar();//防闪退
	return 0;
}
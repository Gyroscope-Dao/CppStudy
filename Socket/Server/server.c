#include"../tcpSocket/tcpSocket.h"

int main() {

	init_Socket();

	SOCKET serfd = createServerSocket();
	printf("wait client connect...\n");
	//如果有客户端请求连接
	SOCKET clifd = accept(serfd, NULL, NULL);
	if (INVALID_SOCKET == clifd) {//失败
		err("accept");
	}

	//可以和客户端进行通信了
	char sendbuf[BUFSIZ] = { 0 };
	char recvbuf[BUFSIZ] = { 0 };
	while (true) {
		//recv从指定的socket接受信息
		if (0 < recv(clifd, recvbuf, BUFSIZ, 0)) {//成功
			printf("recv:%s\n", recvbuf);
		}

		//发送消息
		printf("send>");
		memset(sendbuf,0,sizeof(sendbuf));
		gets_s(sendbuf, BUFSIZ);
		if (SOCKET_ERROR == send(clifd, sendbuf, strlen(sendbuf), 0)) {//失败
			err("send");
		}
	}
	

	closesocket(clifd);
	closesocket(serfd);

	close_Socket();
	printf("server-----end-----\n");

	getchar();//防闪退
	return 0;
}
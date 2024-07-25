#include"tcpSocket.h"

bool init_Socket()
{
	//wsa windows socket async   windows异步套接字
	//parm1：请求socket版本  2.2  2.1  1.0     parm2：传出参数
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) {//!=0 失败
		printf("WSAStartup failed code %d", WSAGetLastError());
		return false;
	}
	return true;
}

bool close_Socket()
{	
	if (0 != WSACleanup()) {
		printf("WSACleanup failed code %d", WSAGetLastError());
		return false;
	}
	return true;
}

SOCKET createServerSocket()
{
	//1、创建空的Socket  买新手机
	//parm1: af  地址协议族  ipv4  ipv6
	//parm2: type 传输协议类型   流式套接字  数据报套接字
	//parm3: protocol 使用具体的某个传输协议
	SOCKET fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (fd == INVALID_SOCKET) {//失败
		err("socket");
		return INVALID_SOCKET;
	}

	//2、给socket绑定ip地址和端口号   买卡才能打电话
	struct sockaddr_in addr;
	addr.sin_family = AF_INET; //和创建socket时的必须一样
	addr.sin_port = htons(PORT);//htons()本地字节序转网络字节序		//大端存储 和 小端存储
	addr.sin_addr.S_un.S_addr = ADDR_ANY;//绑定本机任意网卡的任意ip //或者 inet_addr("127.0.0.1");//点分十进制 -》二进制

	if (SOCKET_ERROR == bind(fd, &addr, sizeof(addr))) {//失败
		err("bind");
		return false;
	}

	//3、监听电话
	listen(fd, 10);

	return fd;
}

SOCKET createClientSocket(const char *ip)
{
	//1、创建空的Socket  买新手机
	//parm1: af  地址协议族  ipv4  ipv6
	//parm2: type 传输协议类型   流式套接字  数据报套接字
	//parm3: protocol 使用具体的某个传输协议
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET) {//失败
		err("socket");
		return INVALID_SOCKET;
	}

	//2、与服务器建立连接
	struct sockaddr_in addr;
	addr.sin_family = AF_INET; //和创建socket时的必须一样
	addr.sin_port = htons(PORT);//htons()本地字节序转网络字节序		//大端存储 和 小端存储
	addr.sin_addr.S_un.S_addr = inet_addr(ip);//点分十进制 -》二进制
	if (INVALID_SOCKET == connect(fd, (struct sockaddr_in*)&addr, sizeof(addr))) {//失败
		err("connect");
		return false;
	}

	return fd;
}

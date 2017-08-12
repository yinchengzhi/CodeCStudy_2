#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock.h>

//网络通信
#pragma comment(lib,"ws2_32.lib")

void main() {
	char sendbuf[256] = { 0 };		     									//发送的消息
	char receivebuf[256] = { 0 };											 //收到的消息
	int sendlength = 0;
	int receivelength = 0;												    //发送收到的长度

	SOCKET  socket_send; 													//通信套接字
	SOCKADDR_IN server_addr;											    //链接的套接字

	WORD wversion = MAKEWORD(2, 2);											//版本
	WSADATA wsadata;														//版本

	int error = WSAStartup(wversion, &wsadata);								//和获取版本对比，开始通信
	if (error != 0) {
		printf("error");
		return;
	}

	//取出低八位，高八位，对比版本
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2) {
		printf("version error");
		return;
	}

	//设置连接地址
	server_addr.sin_family = AF_INET;								       //通信
	server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(9982);								       //端口

	//设定发送的相关信息
	socket_send = socket(AF_INET, SOCK_STREAM, 0);

	connect(socket_send, (SOCKADDR *)&server_addr, sizeof(SOCKADDR));     //链接

	while (1) {
		printf("\n海华，你想对芳芳说啥");
		scanf("%s", sendbuf);
		sendlength = send(socket_send, sendbuf, 256, 0);
		memset(receivebuf, 0, 256);										  //清零

		receivelength = recv(socket_send, receivebuf, 256, 0);
		printf("\n芳芳对你说%s", receivebuf);
		memset(sendbuf, 0, 256);										  //清零
	}

	closesocket(socket_send);											  //关闭网络

	WSACleanup();														  //关闭
}
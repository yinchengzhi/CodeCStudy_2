#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock.h>

//网络通信
#pragma comment(lib,"ws2_32.lib")

void main() {
	char sendbuf[256] = { 0 };		     		//发送的消息
	char receivebuf[256] = { 0 };               //收到的消息
	int sendlength = 0;
	int receivelength = 0;						//发送收到的长度
	int length;									//SOCKADDR，地址长度

	SOCKET socket_server;						//服务器套接字
	SOCKET socket_receive;						//链接的套接字

	SOCKADDR_IN server_addr;					//服务器地址
	SOCKADDR_IN client_addr;					//客户端地址

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

	//设置连接地址
	server_addr.sin_family = AF_INET;					//通信
	server_addr.sin_addr.S_un.S_addr = htons(INADDR_ANY);			//获取本地地址
	//创建套接字，接受消息

	//绑定地址，端口

	//监听

}
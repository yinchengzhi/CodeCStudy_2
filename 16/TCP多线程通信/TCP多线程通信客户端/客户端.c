#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define port 5529
#define ip_addr "127.0.0.1"

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

	}
}
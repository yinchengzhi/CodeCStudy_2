#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#include<process.h>
#pragma comment(lib, "ws2_32.lib")

#define port 5529
#define ip_addr "192.168.191.1"

char sendbuf[256] = { 0 };
HANDLE event;			//事件
HANDLE mutex = NULL;

//创建线程
DWORD WINAPI clientthread(void *p) {
	SOCKET client = (SOCKET)p;					              //参数指针类型转换
	int Ret = 0;
	char receivebuf[256];
	while (1) {
		//memset(receivebuf, 0, 256);					          //清零
		//Ret = recv(client, receivebuf, 256, 0);		          //读取
		//if (Ret == SOCKET_ERROR) {
		//	puts("客户端send 失败");
		//	break;
		//}
		//printf("\n收到%s", receivebuf);
		WaitForSingleObject(event, INFINITE);
		if (strlen(sendbuf) != 0) {
			Ret = send(client, sendbuf, strlen(sendbuf), 0);		          //读取
		}

		ResetEvent(event);										//手动复位
	}
	return 0;
}

//服务器

void mains(void *p) {
	WSADATA WSA;							                 //对比版本
	SOCKET client, server;					                 //客户端
	struct sockaddr_in localeaddr,clientaddr;                //服务器地址
	int addrlength = 0;
	HANDLE hthread = NULL;				                     //线程句柄
	int Ret = 0;							                 //
	char senbuf[256] = { 0 };

	if (WSAStartup(MAKEWORD(2, 2), &WSA) != 0) {
		puts("版本不一致，通信失败");
		system("pause");
		return;
	}

	server = socket(AF_INET, SOCK_STREAM, 0);		         //通信
	if (server==INVALID_SOCKET) {
		puts("服务器创建失败");
		system("pause");
		return;
	}
	localeaddr.sin_family = AF_INET;
	localeaddr.sin_addr.S_un.S_addr = inet_addr(ip_addr);
	localeaddr.sin_port = htons(port);

	memset(localeaddr.sin_zero, 0x00, 8);			        //清零
	Ret = bind(server, (struct sockaddr*)&localeaddr, sizeof(localeaddr));	//绑定
	if (Ret != 0) {
		puts("绑定失败");
		system("pause");
		return;
	}
	Ret = listen(server, 5);
	if (Ret != 0) {
		puts("监听失败");
		system("pause");
		return;
	}
	puts("服务器启动\n");
	while (1) {
		addrlength = sizeof(clientaddr);						                   //获取长度
		client = accept(server, (struct sockaddr*)&clientaddr, &addrlength);		//接收客户端请求
		if (client == INVALID_SOCKET) {
			puts("接收失败");
			system("pause");
			return;
		}
		printf("\n客户端连接%s %d", inet_ntoa(clientaddr.sin_addr),clientaddr.sin_port);

		hthread = CreateThread(NULL, 0, clientthread, (void *)client, 0, NULL);

	}

	closesocket(server);
	closesocket(client);
	WSACleanup();
}


void main() {

	event = CreateEvent(NULL, TRUE, FALSE, NULL);
	_beginthread(mains, 0, NULL);
	while (1) {
		scanf("%s", sendbuf);
		SetEvent(event);

	}

	system("pause");
}


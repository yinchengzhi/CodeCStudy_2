#include<stdio.h>
#include<stdlib.h>
#include<winsock.h>
#include<process.h>

#pragma comment(lib,"ws2_32.lib")

#define port 5529
#define ip_addr "192.168.1.198"
char senbuf[256] = { 0 };
HANDLE event = NULL;					//事件
HANDLE mutex = NULL;

//创建线程
DWORD WINAPI clientthread(void* p) {
	SOCKET client = (SOCKET)p;            ////数指针类型转换
	int Ret = 0;
	//char receivebuf[256]
	while (1) {
		WaitForSingleObject(event, INFINITE);			//等待事件

		if (strlen(senbuf) != 0) {
			Ret = send(client, senbuf, strlen(senbuf), 0);
		}
		ResetEvent(event);                //手动复位
	}
}

//创建线程
//服务器

void main(void *p) {
	WSADATA WSA;                                   //对比版本
	SOCKET client, server;                         //客户端

	struct sockaddr_in localaddr, clientaddr;      //服务器地址
	int addrlength = 0;
	HANDLE hthread = NULL;                         //线程句柄
	int Ret = 0;
	char senbuf[256] = { 0 };

	if (WSAStartup(MAKEWORD(2, 2), &WSA)) {
		puts("版本不一致, 通信失败");
		system("pause");
		return;
	}
	server = socket(AF_INET, SOCK_STREAM, 0);       //通信
	if (server == INVALID_SOCKET) {
		puts("服务器创建失败");
		system("pause");
		return;
	}
	localaddr.sin_family = AF_INET;
	localaddr.sin_addr.S_un.S_addr = inet_addr(ip_addr);
	localaddr.sin_port = htons(port);
	memset(localaddr.sin_zero, 0x00, 8);			//清零

	Ret = bind(server, (struct sockaddr*)&localaddr, sizeof(localaddr));
	
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
		addrlength = sizeof(clientaddr);			//获取长度
		client = accept(server, (struct sockaddr*)&clientaddr, &addrlength);		//接受客户端轻轻
		if (client == INVALID_SOCKET) {
			puts("接收失败");
			system("pause");
		}
	}

}










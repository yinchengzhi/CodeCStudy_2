#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock.h>

//网络通信
#pragma comment(lib,"ws2_32.lib")

void main() {

	SOCKET socket_client;								//客户端的套接字编号
	SOCKADDR_IN server;									//保存服务器

	WORD wversion = MAKEWORD(2, 2);							//版本
	WSADATA wsadata;										//版本

	int error = WSAStartup(wversion, &wsadata);				//和获取版本对比，开始通信
	if (error != 0) {
		printf("error");
		return;
	}

	//取出低八位，高八位，对比版本
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2){
		printf("version error");
		return;
	}

	socket_client = socket(AF_INET, SOCK_DGRAM, 0);			//初始化 

	server.sin_family = AF_INET;						    //设置通信模式
	server.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");	//设置本地
	server.sin_port = htons(6888);							//开启通信端口

	while (1) {
		system("pause");
		FILE *pf = fopen("C:\\Users\\olydebug\\Pictures\\邓丽欣\\time.jpg", "rb");
		while (!feof(pf)) {
			char str[256] = { 0 };
			//fgets(str, 1024, pf);
			fread(str, sizeof(char), 256, pf);
			//printf("%s", str);
			sendto(socket_client, str, sizeof(str) + 1, 0, &server, sizeof(SOCKADDR));
		}

		fclose(pf);
		break;
	}

	closesocket(socket_client);
	WSACleanup();
	system("pause");
}


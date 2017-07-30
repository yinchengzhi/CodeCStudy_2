#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock.h>

//网络通信
#pragma comment(lib,"ws2_32.lib")

void main2() {

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
	server.sin_port = htons(8848);							//开启通信端口

	while (1) {
		char str[128] = { 0 };
		scanf("%s", str);
		sendto(socket_client, str, strlen(str) + 1, 0, &server,sizeof(SOCKADDR));

	}

	closesocket(socket_client);
	WSACleanup();
	system("pause");
}

int ylss_strcmp(char *s, char *t) {
	while(*s!='\0'&&(*s++==*t++)){ }
	return *s - *t;
}

int ycz_strcmp(char *s, char *t) {
	while (*s == *t) {
		*s++;
		*t++;
	}
	return *s - *t;
}

int strcmp_1(const char *str1, const char *str2)
{
	/*不可用while(*str1++==*str2++)来比较，当不相等时仍会执行一次++，
	return返回的比较值实际上是下一个字符。应将++放到循环体中进行。*/
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

void main2() {
	char s1[20] = { 0 };
	char s2[20] = { 0 };
	printf("please input your String1:");
	gets(s1);
	printf("please input your String1:");
	gets(s2);
	printf("比较的结果是: %d", ycz_strcmp(s1, s2));
	
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock.h>

//����ͨ��
#pragma comment(lib,"ws2_32.lib")

void main2() {

	SOCKET socket_client;								//�ͻ��˵��׽��ֱ��
	SOCKADDR_IN server;									//���������

	WORD wversion = MAKEWORD(2, 2);							//�汾
	WSADATA wsadata;										//�汾

	int error = WSAStartup(wversion, &wsadata);				//�ͻ�ȡ�汾�Աȣ���ʼͨ��
	if (error != 0) {
		printf("error");
		return;
	}

	//ȡ���Ͱ�λ���߰�λ���ԱȰ汾
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2){
		printf("version error");
		return;
	}

	socket_client = socket(AF_INET, SOCK_DGRAM, 0);			//��ʼ�� 

	server.sin_family = AF_INET;						    //����ͨ��ģʽ
	server.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");	//���ñ���
	server.sin_port = htons(8848);							//����ͨ�Ŷ˿�

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
	/*������while(*str1++==*str2++)���Ƚϣ��������ʱ�Ի�ִ��һ��++��
	return���صıȽ�ֵʵ��������һ���ַ���Ӧ��++�ŵ�ѭ�����н��С�*/
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
	printf("�ȽϵĽ����: %d", ycz_strcmp(s1, s2));
	
	system("pause");
	return 0;
}
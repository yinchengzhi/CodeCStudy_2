#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock.h>

//����ͨ��
#pragma comment(lib,"ws2_32.lib")

void main() {

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
	server.sin_port = htons(6888);							//����ͨ�Ŷ˿�

	while (1) {
		system("pause");
		FILE *pf = fopen("C:\\Users\\olydebug\\Pictures\\������\\time.jpg", "rb");
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


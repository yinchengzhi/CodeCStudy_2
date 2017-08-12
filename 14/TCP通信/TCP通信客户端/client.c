#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock.h>

//����ͨ��
#pragma comment(lib,"ws2_32.lib")

void main() {
	char sendbuf[256] = { 0 };		     									//���͵���Ϣ
	char receivebuf[256] = { 0 };											 //�յ�����Ϣ
	int sendlength = 0;
	int receivelength = 0;												    //�����յ��ĳ���

	SOCKET  socket_send; 													//ͨ���׽���
	SOCKADDR_IN server_addr;											    //���ӵ��׽���

	WORD wversion = MAKEWORD(2, 2);											//�汾
	WSADATA wsadata;														//�汾

	int error = WSAStartup(wversion, &wsadata);								//�ͻ�ȡ�汾�Աȣ���ʼͨ��
	if (error != 0) {
		printf("error");
		return;
	}

	//ȡ���Ͱ�λ���߰�λ���ԱȰ汾
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2) {
		printf("version error");
		return;
	}

	//�������ӵ�ַ
	server_addr.sin_family = AF_INET;								       //ͨ��
	server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(9982);								       //�˿�

	//�趨���͵������Ϣ
	socket_send = socket(AF_INET, SOCK_STREAM, 0);

	connect(socket_send, (SOCKADDR *)&server_addr, sizeof(SOCKADDR));     //����

	while (1) {
		printf("\n����������Է���˵ɶ");
		scanf("%s", sendbuf);
		sendlength = send(socket_send, sendbuf, 256, 0);
		memset(receivebuf, 0, 256);										  //����

		receivelength = recv(socket_send, receivebuf, 256, 0);
		printf("\n��������˵%s", receivebuf);
		memset(sendbuf, 0, 256);										  //����
	}

	closesocket(socket_send);											  //�ر�����

	WSACleanup();														  //�ر�
}
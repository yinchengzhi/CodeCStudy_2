#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock.h>

//����ͨ��
#pragma comment(lib,"ws2_32.lib")

void main() {
	char sendbuf[256] = { 0 };		     		//���͵���Ϣ
	char receivebuf[256] = { 0 };               //�յ�����Ϣ
	int sendlength = 0;
	int receivelength = 0;						//�����յ��ĳ���
	int length;									//SOCKADDR����ַ����

	SOCKET socket_server;						//�������׽���
	SOCKET socket_receive;						//���ӵ��׽���

	SOCKADDR_IN server_addr;					//��������ַ
	SOCKADDR_IN client_addr;					//�ͻ��˵�ַ

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

	//�������ӵ�ַ
	server_addr.sin_family = AF_INET;								//ͨ��
	server_addr.sin_addr.S_un.S_addr = htons(INADDR_ANY);			//��ȡ���ص�ַ
	server_addr.sin_port = htons(9982);								//�˿�
	
	//�����׽��֣�������Ϣ   SOCK_STREAM��
	socket_server = socket(AF_INET, SOCK_STREAM, 0);				//����
	//�󶨵�ַ���˿�
	bind(socket_server, (SOCKADDR *)&server_addr, sizeof(SOCKADDR));
	//����
	listen(socket_server, 5);										//���ȴ���ĿΪ5

	length = sizeof(SOCKADDR);
	//��������
	socket_receive = accept(socket_server, (SOCKADDR*)&client_addr, &length);

}
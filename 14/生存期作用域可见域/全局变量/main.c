#include<stdio.h>

extern int num;		//extern �Ӳ��Ӷ����� ����ȫ�ֱ���

//ȫ�ֱ���Ĭ���ڴ�ȫ������
int data;

void main() {			//extern���Խ�ȫ�ֱ���x,y��������չ���ֲ�����
	printf("%d", data);
	getchar();
}

int data = 20;
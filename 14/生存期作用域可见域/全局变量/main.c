#include<stdio.h>

extern int num;		//extern �Ӳ��Ӷ����� ����ȫ�ֱ���

//ȫ�ֱ���Ĭ���ڴ�ȫ������
int data;
int a = 10;
//int b = a + 1;		ȫ�ֱ�������̬ȫ�ֱ�������ʼ������ʹ�ñ�����ʼ����ֻ�ܳ���

void main() {			//extern���Խ�ȫ�ֱ���x,y��������չ���ֲ�����
	printf("%d", data);
	getchar();
}

int data = 20;
#include<stdio.h>
#include<stdlib.h>

extern int a;				//����ȫ�ֱ���

int runx() {
	int b = 0;
	a = 1;					//��ʱ�˿̿��Է��ʵ����÷�Χ�ɼ�����

}

int a = 10;					//������ȫ�ֱ�����������ȫ�֣����ȼ����÷�Χ

void main() {

	//�ܷ�����ĸ�������֮Ϊ�ɼ���
	a = 10;
}
#include<stdio.h>
#include<stdlib.h>

void main() {

	//a = 3;
	for (int i = 0; i < 10; i++) {
		static int a = 0;										//ֻ���ʼ��һ�Σ��洢�ھ�̬��������򹲴���
		a += i;
		printf("\n%d,%d", i, a);
	}

	system("pause");
}
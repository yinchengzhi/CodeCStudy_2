#include<stdio.h>
#include<stdlib.h>

int numA = 100;						//ȫ�ֱ��������ڴ���һֱ���ڣ�һֱ���������

									//�ֲ�������ֻ�е��ú�����ʱ��Ż���з��䣬����������ɵ�ʱ��ͻ����
void printdata() {
	int data = 10;
	printf("%p,%d\n", &data, data);
	printf("%p,%d\n", &numA, numA);

	printf("\n");
}


//��ȫ�ֱ��������ڴ�,������main����
void main() {

	printf("%p\n", &numA);

	printdata();

	printf("\n");

	printdata();

	printf("\n");

	system("pause");
}
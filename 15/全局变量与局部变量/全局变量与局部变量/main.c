#include<stdio.h>
#include<stdlib.h>

void go(int num) {

	//printf("%d", a);				C�����Ǵ������¿�ʼ����,ǰ��û�ж��壬���޷�����
	num = 11;						//numҲ�Ǿֲ�����
	int a = 10;						//a�Ǿֲ�����
	printf("%d", a);
	printf("%d", num);
}

void run(int num) {					//��ʽ�����ֲ�����
	int data = 10;					//�ֲ�����
	num = 9;						//�ֲ�����
	printf("%x,%x", &num, &data);
	
	printf("\n");
}

void main1() {

	//printf("%d",a);				//a�����÷�Χ���ǵ�7�е���������
	//printf("%d",num);				//numֻ�ܴӺ�����ʼ�����������ķ�Χ������ 

	system("pause");
}

//�ֲ��������ں������õ�ʱ�򣬲ŷ����ڴ棬����ִ����ɵ�ʱ��
//�ͻ����ڴ棬Ȼ����������
//�ֲ�����һ�㶨���ں����ڲ�
void main2() {

	run(5);

	printf("\n\n");

	run(5);

	printf("\n\n");

	system("pause");
}

void print() {
	//printf("%d", a);					//a�Ǿֲ������޷�����
}

void main() {
	int a = 10;							//�ֲ����������÷�Χ�Ӷ��忪ʼ��main��������
}
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

void main3() {
	// printf("%d",a);					//C���Դ������¿�ʼ���룬ǰ��û�м�⵽�����޷�����
	int a = 10;							//�ֲ����������÷�Χ�Ӷ��忪ʼ��main��������
	printf("%d", a);
}

void test1() {
	int a = 10;
	printf("%d,%p\n", a, &a);			//�ֲ����������˾������ͷ�

	printf("\n");
}

void test2() {
	int a = 101;
	printf("%d,%p\n", a, &a);

	printf("\n");
}

//��ͬ������ͬ����������Щ������Ϊ���Ż������Ե�ַ��һ����
//���ǵ��������ڲ�һ�������Բ��������
//��ַ�ȷ����test1��a���������ͷţ��ٴη���test2��a
//��������������Ӱ��,��Ϊ���������Ǵ���

void main4() {

	test1();

	printf("\n");

	test2();

	system("pause");
}

//�����������غϵı��������Ǿ�Ҫ���Ÿ���ͬ�ĵ�ַ,��������

//��ͬ�ĺ��������Զ���ͬ���ľֲ�����
//����������ڲ��غϣ����������Ż�����ʹ��ͬһ�ڴ浥Ԫ
//���������غϣ��ͻ�ʹ�ò�ͬ���ڴ浥Ԫ�����ʱ��Ͳ����ͻ

void testlast() {
	int num = 10;
	printf("testlast = %d,%x", num, &num);
}


void main5() {
	int num = 11;
	printf("main = %d,%x\n", num, &num);
	testlast();

	getchar();
}

//��ͬ�Ŀ���䣬���Զ���ͬ���ľֲ����������������Զ����Ų�ͬ�ĵ�ַ
void main6() {
	int num = 11;
	//int num = 111;		ͬһ��������ڲ�������������������ͬ�ı���
	//Υ��
	printf("main = %d,%x\n", num, &num);
	{
		int num = 11;
		printf("main1 = %d,%x\n", num, &num);
		{
			int num = 11;
			printf("main2 = %d,%x\n", num, &num);
		}
	}

	getchar();
}
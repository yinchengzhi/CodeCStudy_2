#include<stdio.h>
#include<stdlib.h>

int numA = 100;						//全局变量，在内存中一直存在，一直到程序结束

									//局部变量，只有调用函数的时候才会进行分配，函数调用完成的时候就会结束
void printdata() {
	int data = 10;
	printf("%p,%d\n", &data, data);
	printf("%p,%d\n", &numA, numA);

	printf("\n");
}


//给全局变量分配内存,优先于main函数
void main() {

	printf("%p\n", &numA);

	printdata();

	printf("\n");

	printdata();

	printf("\n");

	system("pause");
}
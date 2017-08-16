#include<stdio.h>
#include<stdlib.h>

void go(int num) {

	//printf("%d", a);				C语言是从上往下开始编译,前面没有定义，就无法访问
	num = 11;						//num也是局部变量
	int a = 10;						//a是局部变量
	printf("%d", a);
	printf("%d", num);
}

void run(int num) {					//形式参数局部变量
	int data = 10;					//局部变量
	num = 9;						//局部变量
	printf("%x,%x", &num, &data);
	
	printf("\n");
}

void main1() {

	//printf("%d",a);				//a的作用范围就是第7行到函数结束
	//printf("%d",num);				//num只能从函数开始到函数结束的范围来访问 

	system("pause");
}

//局部变量，在函数调用的时候，才分配内存，函数执行完成的时候
//就回收内存，然后用作他用
//局部变量一般定义在函数内部
void main2() {

	run(5);

	printf("\n\n");

	run(5);

	printf("\n\n");

	system("pause");
}

void print() {
	//printf("%d", a);					//a是局部变量无法访问
}

void main() {
	int a = 10;							//局部变量，作用范围从定义开始到main函数结束
}
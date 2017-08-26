#include<stdio.h>
#include<stdlib.h>

void fun1(int x, int y) {			//函数的副本机制，重新构建的变量
	int z = 10;						//z = 10
	x += 10;						//x = 20
	y += 10;						//y = 20
	if (z) {
		int z = 20;					//屏蔽，同名的情况下，块语句内部的变量生效
		printf("x = %d y =%d z = %d\n", x, y, z);			//20,20,20
	}
	printf("x = %d y = %d z = %d\n", x, y, z);			//20,20,10
}

void main7() {
	int x = 10, y = 10, z = 10;
	//fun(x, y);						//函数除非传地址，否则因为副本机制不会改变x,y
	printf("x = %d y = %d z = %d\n", x, y, z);			//10,10,10

	system("pause");
}

/*
   全局变量软件工程规范，C语言严格区分大小写，
   全局变量，不单独属于任何一个函数。作用域范围内，任何一个函数都可以访问
   全局变量，可以进行函数间通信，不用参数与return实现通信
*/


int x, y;
void fun2() {
	int a = 20, b = 10;
	x = x + a + b;					// x = 8 + 20 + 10 = 38	
	y = y + a - b;                  // y = 2 + 20 - 10 = 12
}

int main8() {
	int a = 5, b = 3;
	x = a + b;							//x = 8
	y = a - b;							//y = 2
	fun2();
	printf("%d,%d", x, y);
	getchar();
	return 0;
}
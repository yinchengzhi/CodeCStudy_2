#include<stdio.h>
#include<stdlib.h>

void fun(int x, int y) {			//函数的副本机制，重新构建的变量
	int z = 10;						//z = 10
	x += 10;						//x = 20
	y += 10;						//y = 20
	if (z) {
		int z = 20;					//屏蔽，同名的情况下，块语句内部的变量生效
		printf("x = %d y =%d z = %d\n", x, y, z);			//20,20,20
	}
	printf("x = %d y = %d z = %d\n", x, y, z);			//20,20,10
}

void main() {
	int x = 10, y = 10, z = 10;
	fun(x, y);						//函数除非传地址，否则因为副本机制不会改变x,y
	printf("x = %d y = %d z = %d\n", x, y, z);			//10,10,10

	system("pause");
}
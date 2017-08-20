#include<stdio.h>
#include<stdlib.h>

void fun(int x, int y) {			//函数的副本机制，重新构建的变量
	int z = 10;
	x += 10;
	y += 10;
	if (z) {
		int z = 20;
		printf("x = %d y =%d z = %d\n", x, y, z);
	}
	printf("x = %d y = %d z = %d\n", x, y, z);
}

void main() {
	int x = 10, y = 10, z = 10;
	fun(x, y);						//函数除非传地址，否则因为副本机制不会改变x,y
	printf("x = %d y = %d z = %d\n", x, y, z);

	system("pause");
}
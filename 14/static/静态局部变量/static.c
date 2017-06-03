#include<stdio.h>
#include<stdlib.h>

void main() {

	//a = 3;
	for (int i = 0; i < 10; i++) {
		//静态局部变量，作用域创建到块语句结束
		static int a = 0;										//只会初始化一次，存储在静态区，与程序共存亡
		a += i;
		printf("\n%d,%d", i, a);
	}

	system("pause");
}
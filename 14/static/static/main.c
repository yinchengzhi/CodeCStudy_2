#include<stdio.h>
#include<stdlib.h>

static void run() {				//改变为局部函数，作用域当前文件，屏蔽全局函数
	puts("huahua");
	getchar();
}

//int a;							//全局变量，跨文件使用
static int a = 35;					//可以屏蔽外部变量，作用范围当前文件
//静态全局变量，作用范围，当前文件

void main() {
	//run();

	printf("%d", a);

	getchar();
}
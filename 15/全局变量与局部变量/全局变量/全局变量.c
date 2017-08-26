#include<stdio.h>
#include<stdlib.h>

int num = 10;						//定义在函数外部的变量就是全局变量

//从定义到文件

void go() {
	printf("%d", num);
}

void main9() {
	printf("%d", num); {
		printf("%d", num); {
			printf("%d", num);
		}
	}
}
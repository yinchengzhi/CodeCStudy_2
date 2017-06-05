#include<stdio.h>



void main() {

	auto int a;					//标识我是局部变量

	auto b, c, d;
	int x = 10;
	printf("\n%d", x); {
		printf("\n%d", x);
		int x = 30;
		printf("\n%d", x); {
			printf("\n%d", x);
			int x = 40;
			printf("\n%d", x); {
				printf("\n%d", x);
				int x = 10;
				printf("\n%d", x);
			}
			printf("\n%d", x);
		}
		printf("\n%d", x);
	}

	getchar();
}
#include<stdio.h>



void main() {

	auto int a;					//��ʶ���Ǿֲ�����

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
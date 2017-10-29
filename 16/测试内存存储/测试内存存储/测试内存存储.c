#include<stdio.h>
#include<stdlib.h>

void main() {

	int a = 0x01020304;
	char *p = &a;

	for (int i = 0; i < 4; i++) {
		printf("%u ", *(p + i));
	}

	system("pause");
}
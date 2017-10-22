#include<stdio.h>
#include<stdlib.h>

int add(int a, int b) {
	return a + b;
}

int mul(int a, int b) {
	return a*b;
}

void main() {

	int(*p)(int a, int b);		//º¯ÊıÖ¸Õë
	p = add;
	printf("%p", p);

	printf("%d\n", p(100, 200));
	p = mul;
	printf("%d\n", p(100, 200));

	system("pause");
}
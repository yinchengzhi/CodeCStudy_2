#include<stdio.h>
#include<stdlib.h>

struct MyStruct{
	int a = 10;				//C++�ṹ��������Գ�ʼ��
	MyStruct() {			//CPP

	}
	int go() {				//���԰�������

	}
};

void run(int a) {			//C++ ���ݲ���������

}

void run() {

}

//�ж�һ���ֽ��б���Ϊ1��λ�ĸ���
unsigned int TestAsOne0(char log) {
	int i;
	unsigned int num = 0, val;
	for (i = 0; i < 8; i++) {
		val = log >> i;		//��λ
		val &= 0x01;       //��1����
		if (val)
			num++;
	}
	return num;
}

int Invert(char *str) {
	int num = 0;
	while (*str = '\0') {
		int digital = *str - 48;
		num = num * 10 + digital;
		str = str + 1;
	}
	return num;
}

void FourToSeven() {
	unsigned a, b, c, d;
	scanf("%o", &a);
	b = a >> 4;
	c = ~(~0 << 4);
	d = b&c;
	printf("%o\n%o\n", a, d);
}

void main() {
	void *p = malloc(0);
	printf("%p", p);

	getchar();
}
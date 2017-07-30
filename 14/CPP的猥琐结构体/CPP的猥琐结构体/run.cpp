#include<stdio.h>
#include<stdlib.h>

struct MyStruct{
	int a = 10;				//C++结构体变量可以初始化
	MyStruct() {			//CPP

	}
	int go() {				//可以包含函数

	}
};

void run(int a) {			//C++ 根据参数区别函数

}

void run() {

}

//判断一个字节中被置为1的位的个数
unsigned int TestAsOne0(char log) {
	int i;
	unsigned int num = 0, val;
	for (i = 0; i < 8; i++) {
		val = log >> i;		//移位
		val &= 0x01;       //与1相与
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
#include<stdio.h>
#include<stdlib.h>

void fun(int x, int y) {			//�����ĸ������ƣ����¹����ı���
	int z = 10;						//z = 10
	x += 10;						//x = 20
	y += 10;						//y = 20
	if (z) {
		int z = 20;					//���Σ�ͬ��������£�������ڲ��ı�����Ч
		printf("x = %d y =%d z = %d\n", x, y, z);			//20,20,20
	}
	printf("x = %d y = %d z = %d\n", x, y, z);			//20,20,10
}

void main() {
	int x = 10, y = 10, z = 10;
	fun(x, y);						//�������Ǵ���ַ��������Ϊ�������Ʋ���ı�x,y
	printf("x = %d y = %d z = %d\n", x, y, z);			//10,10,10

	system("pause");
}
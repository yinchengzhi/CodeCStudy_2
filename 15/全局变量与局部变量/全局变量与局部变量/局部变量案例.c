#include<stdio.h>
#include<stdlib.h>

void fun(int x, int y) {			//�����ĸ������ƣ����¹����ı���
	int z = 10;
	x += 10;
	y += 10;
	if (z) {
		int z = 20;
		printf("x = %d y =%d z = %d\n", x, y, z);
	}
	printf("x = %d y = %d z = %d\n", x, y, z);
}

void main() {
	int x = 10, y = 10, z = 10;
	fun(x, y);						//�������Ǵ���ַ��������Ϊ�������Ʋ���ı�x,y
	printf("x = %d y = %d z = %d\n", x, y, z);

	system("pause");
}
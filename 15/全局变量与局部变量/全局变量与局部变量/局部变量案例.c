#include<stdio.h>
#include<stdlib.h>

void fun1(int x, int y) {			//�����ĸ������ƣ����¹����ı���
	int z = 10;						//z = 10
	x += 10;						//x = 20
	y += 10;						//y = 20
	if (z) {
		int z = 20;					//���Σ�ͬ��������£�������ڲ��ı�����Ч
		printf("x = %d y =%d z = %d\n", x, y, z);			//20,20,20
	}
	printf("x = %d y = %d z = %d\n", x, y, z);			//20,20,10
}

void main7() {
	int x = 10, y = 10, z = 10;
	//fun(x, y);						//�������Ǵ���ַ��������Ϊ�������Ʋ���ı�x,y
	printf("x = %d y = %d z = %d\n", x, y, z);			//10,10,10

	system("pause");
}

/*
   ȫ�ֱ���������̹淶��C�����ϸ����ִ�Сд��
   ȫ�ֱ����������������κ�һ��������������Χ�ڣ��κ�һ�����������Է���
   ȫ�ֱ��������Խ��к�����ͨ�ţ����ò�����returnʵ��ͨ��
*/


int x, y;
void fun2() {
	int a = 20, b = 10;
	x = x + a + b;					// x = 8 + 20 + 10 = 38	
	y = y + a - b;                  // y = 2 + 20 - 10 = 12
}

int main8() {
	int a = 5, b = 3;
	x = a + b;							//x = 8
	y = a - b;							//y = 2
	fun2();
	printf("%d,%d", x, y);
	getchar();
	return 0;
}
#include<stdio.h>
#include<stdlib.h>

int num = 10;						//�����ں����ⲿ�ı�������ȫ�ֱ���

//�Ӷ��嵽�ļ�

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
#include<stdio.h>
#include<stdlib.h>

//extern ��һ�����п��޵Ľ�ɫ
extern int a;
extern int a = 10;

static void run() {			//�޶����ļ�

}

static void run();			//�޶����ļ�
extern void run1();			//����

void main() {

	run1();
}

extern void run1() {		//extern ��д�ɲ�д��Ĭ�Ϻ���extern����,ȫ�ֵ���

}
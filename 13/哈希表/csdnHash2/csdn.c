#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char path[256] = "H:\\2.txt";
#define N 36
unsigned int BKDRHash(char *str);

struct beitai{
	char *pstr;															//�洢�ַ���
	struct beitai *pNext;												//��һ���ڵ�
};

struct info {
	struct beitai *pbt;
};

struct info *pall = NULL;

//ʵ�ֲ���
struct beitai *addstr(struct beitai *phead,char *str) {
	struct beitai *pnew = calloc(1, sizeof(struct beitai));				//���ٽڵ�
	int length = strlen(str);
	pnew->pstr = calloc(length + 1, sizeof(char));
	strcpy(pnew->pstr, str);											//����
	if (phead == NULL) {
		phead = pnew;
	}
	else {
		pnew->pNext = phead;
		phead = pnew;
	}
	return phead;
}

//ʵ���޸�,��ѯ
void find(struct beitai *phead, char *findstr) {
	while (phead != NULL) {
		char *ps = strstr(phead->pstr, findstr);
		if (ps!=NULL) {
			printf("%s", phead->pstr);						//����
		}
		phead = phead->pNext;
	}
}


//01234567	
//LaoZheng\670203313747 # chengming_zheng@163.com

void changestr(char *str) {
	char *pbak = str;													//���ݵ�ַ
																		//ȥ��''�ַ�
	int i = 0;
	int j = 0;
	while ((str[i] = str[j++]) != '\0') {
		if (str[i] != ' ') {
			i++;
		}
	}
	char *p1 = strstr(str, "#");
	if (p1 != NULL) {
		*p1 = '\0';
	}

}

void init() {
	int k = 0;
	pall = malloc(N * sizeof(struct info));
	memset(pall, 0, N * sizeof(struct info));
	FILE *pf = fopen(path, "r");
	for (int i = 0; i < N; i++) {
		char str[100] = { 0 };
		char strbak[100] = { 0 };
		fgets(str, 100, pf);												//��ȡ
		strcpy(strbak, str);												//����
		changestr(str);														//�ַ�������
		unsigned int data = BKDRHash(str);
		unsigned int id = data%N;

		pall[id].pbt = addstr(pall[id].pbt, strbak);							//�ҵ�����ڵ㣬����
	}
	fclose(pf);
}

// BKDR Hash Function
unsigned int BKDRHash(char *str) {
	unsigned int seed = 131313; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	while (*str) {
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

int getN() {
	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		int i = 0;
		while (!feof(pf)) {
			char str[100] = { 0 };
			fgets(str, 100, pf);					//��ȡ
			i++;
		}
		fclose(pf);
		return i;
	}
}

void main() {

	//printf("%d\n", getN());
	init();
	while (1) {
		char str[100] = { 0 };
		scanf("%s", str);
		unsigned int id = BKDRHash(str) % N;
		find(pall[id].pbt, str);

	}
	system("pause");
}
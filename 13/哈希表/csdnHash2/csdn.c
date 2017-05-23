#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char path[256] = "H:\\2.txt";
#define N 36
unsigned int BKDRHash(char *str);

struct beitai{
	char *pstr;															//存储字符串
	struct beitai *pNext;												//下一个节点
};

struct info {
	struct beitai *pbt;
};

struct info *pall = NULL;

//实现插入
struct beitai *addstr(struct beitai *phead,char *str) {
	struct beitai *pnew = calloc(1, sizeof(struct beitai));				//开辟节点
	int length = strlen(str);
	pnew->pstr = calloc(length + 1, sizeof(char));
	strcpy(pnew->pstr, str);											//拷贝
	if (phead == NULL) {
		phead = pnew;
	}
	else {
		pnew->pNext = phead;
		phead = pnew;
	}
	return phead;
}

//实现修改,查询
void find(struct beitai *phead, char *findstr) {
	while (phead != NULL) {
		char *ps = strstr(phead->pstr, findstr);
		if (ps!=NULL) {
			printf("%s", phead->pstr);						//查找
		}
		phead = phead->pNext;
	}
}


//01234567	
//LaoZheng\670203313747 # chengming_zheng@163.com

void changestr(char *str) {
	char *pbak = str;													//备份地址
																		//去除''字符
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
		fgets(str, 100, pf);												//读取
		strcpy(strbak, str);												//拷贝
		changestr(str);														//字符串处理
		unsigned int data = BKDRHash(str);
		unsigned int id = data%N;

		pall[id].pbt = addstr(pall[id].pbt, strbak);							//找到链表节点，插入
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
			fgets(str, 100, pf);					//读取
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
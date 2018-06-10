#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

using namespace std;
typedef int QElemType;

//存储结构
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}Qnode, *QueuePtr;

//对头队尾指针
typedef struct {
	QueuePtr front;//对头指针
	QueuePtr rear; //队尾指针
}LinkQueue;

LinkQueue Q;


//构造一个空队列
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

//判断是否为空
bool KoQueue(LinkQueue &Q) {
	if (Q.front == Q.rear) return true;
	return false;
}

//入队
void EnQueue(LinkQueue &Q, QElemType e) {
	Qnode *p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

//出队
void DeQueue(LinkQueue &Q, QElemType &e) {
	//若队列不空，删除Q的对头元素，用e返回其值
	if (KoQueue(Q)) {
		printf("当前无就诊患者！\n");
		return;
	}
	Qnode *p;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
}
//查询
void SearchQueue(LinkQueue &Q) {
	QNode *p;
	if (KoQueue(Q)) {
		printf("当前无排队患者！\n");
		return;
	}
	else {
		printf("当前排队患者：\n");
		p = Q.front->next;
		while (p != NULL) {
			printf("病历号为%d的患者\n", p->data);
			p = p->next;
		}
	}
}
void QuitQueue(LinkQueue &q) {
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}
//排队 就诊，查询，退出

int main() {
	printf("患者看病系统\n\n");
	printf("1.排队\n");
	printf("2.就诊\n");
	printf("3.查询\n");
	printf("4.退出\n\n");
	InitQueue(Q);
	int n = 0;
	int num = 1;
	int nowe;
	while (1) {
		printf("请选择：");
		scanf("%d", &n);
		if (n == 1) {//排队
			EnQueue(Q, num);
			printf("队尾患者病历号为：%d\n", num);
			num++;
		}
		if (n == 2) {//就诊
			DeQueue(Q, nowe);
			printf("当前就诊患者病历号为：%d\n", nowe);
		}
		if (n == 3) {//查询
			SearchQueue(Q);
		}
		if (n == 4) {//退出
			QuitQueue(Q);
			printf("您已成功退出！\n");
			break;
		}
	}
	system("pause");
	return 0;
}
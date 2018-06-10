#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

using namespace std;
typedef int QElemType;

//�洢�ṹ
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}Qnode, *QueuePtr;

//��ͷ��βָ��
typedef struct {
	QueuePtr front;//��ͷָ��
	QueuePtr rear; //��βָ��
}LinkQueue;

LinkQueue Q;


//����һ���ն���
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

//�ж��Ƿ�Ϊ��
bool KoQueue(LinkQueue &Q) {
	if (Q.front == Q.rear) return true;
	return false;
}

//���
void EnQueue(LinkQueue &Q, QElemType e) {
	Qnode *p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

//����
void DeQueue(LinkQueue &Q, QElemType &e) {
	//�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
	if (KoQueue(Q)) {
		printf("��ǰ�޾��ﻼ�ߣ�\n");
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
//��ѯ
void SearchQueue(LinkQueue &Q) {
	QNode *p;
	if (KoQueue(Q)) {
		printf("��ǰ���Ŷӻ��ߣ�\n");
		return;
	}
	else {
		printf("��ǰ�Ŷӻ��ߣ�\n");
		p = Q.front->next;
		while (p != NULL) {
			printf("������Ϊ%d�Ļ���\n", p->data);
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
//�Ŷ� �����ѯ���˳�

int main() {
	printf("���߿���ϵͳ\n\n");
	printf("1.�Ŷ�\n");
	printf("2.����\n");
	printf("3.��ѯ\n");
	printf("4.�˳�\n\n");
	InitQueue(Q);
	int n = 0;
	int num = 1;
	int nowe;
	while (1) {
		printf("��ѡ��");
		scanf("%d", &n);
		if (n == 1) {//�Ŷ�
			EnQueue(Q, num);
			printf("��β���߲�����Ϊ��%d\n", num);
			num++;
		}
		if (n == 2) {//����
			DeQueue(Q, nowe);
			printf("��ǰ���ﻼ�߲�����Ϊ��%d\n", nowe);
		}
		if (n == 3) {//��ѯ
			SearchQueue(Q);
		}
		if (n == 4) {//�˳�
			QuitQueue(Q);
			printf("���ѳɹ��˳���\n");
			break;
		}
	}
	system("pause");
	return 0;
}
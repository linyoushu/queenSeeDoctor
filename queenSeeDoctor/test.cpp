#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <Windows.h>

typedef struct qnode
{
	int data;
	struct qnode *next;
} QNode;            /*���ӽ������*/

typedef struct
{
	QNode *front, *rear;
} QuType;           /*��������*/

void SeeDoctor()
{
	int sel, flag = 1, find, no;
	QuType *qu;
	QNode *p;
	QNode *q;
	qu = (QuType *)malloc(sizeof(QuType));    /*�����ն�*/
	qu->front = qu->rear = NULL;
	while (flag == 1)                             /*ѭ��ִ��*/
	{
		//printf("1:�Ŷ� 2:���� 3:�鿴�Ŷ� 4.�����Ŷ�,�������ξ��� 5:�°�  ��ѡ��:");
		printf("\n\n%20s==============================", " ");
		printf("\n%25s1.�Ŷ�", " ");
		printf("\n%25s2.����", " ");
		printf("\n%25s3.�鿴�Ŷ�", " ");
		printf("\n%25s4.�����Ŷӣ�����һ�ξ���", " ");
		printf("\n%25s5.�°�", " ");
		printf("\n\n%20s==============================", " ");
		printf("\n��ѡ��(0-8)��");
		scanf("%d", &sel);
		switch (sel)
		{
		case 1:
			printf("  >>���벡����:");
			do
			{
				scanf("%d", &no);
				find = 0;
				p = qu->front;
				while (p != NULL && !find)
				{
					if (p->data == no)
						find = 1;
					else
						p = p->next;
				}
				if (find)
					printf("  >>����Ĳ������ظ�,��������:");
			} while (find == 1);
			p = (QNode *)malloc(sizeof(QNode));   /*�������*/
			p->data = no;
			p->next = NULL;
			if (qu->rear == NULL)                 /*��һ�������Ŷ�*/
			{
				qu->front = qu->rear = p;
			}
			else
			{
				qu->rear->next = p;
				qu->rear = p; /*��*p������*/
			}
			break;
		case 2:
			if (qu->front == NULL)                /*�ӿ�*/
				printf("  >>û���ŶӵĲ���!\n");
			else                                /*�Ӳ���*/
			{
				p = qu->front;
				printf("  >>����%d����\n", p->data);
				if (qu->rear == p)            /*ֻ��һ�������Ŷӵ����*/
				{
					qu->front = qu->rear = NULL;
				}
				else
					qu->front = p->next;
				free(p);
			}
			break;
		case 3:
			if (qu->front == NULL)            /*�ӿ�*/
				printf("  >>û�����еĲ���!\n");
			else                            /*�Ӳ���*/
			{
				p = qu->front;
				printf("  >>�ŶӲ���:");
				while (p != NULL)
				{
					printf("%d ", p->data);
					p = p->next;
				}
				printf("\n");
			}
			break;
		case 4:
			if (qu->front == NULL)            /*�ӿ�*/
				printf("  >>û�����еĲ���!\n");
			else                            /*�Ӳ���*/
			{
				p = qu->front;
				printf("  >>���˰�����˳�����:");
				while (p != NULL)
				{
					printf("%d ", p->data);
					p = p->next;
				}
				printf("\n");
			}
			flag = 0;                         /*�˳�*/
			break;
		case 5:
			if (qu->front != NULL)            /*�Ӳ���*/
				printf("  >>���ŶӵĲ��������ҽ!\n");
			printf("��ҽԺ�����ر�");
			printf("      ��л����Ե�����ټ���");
			printf("    ***                 ***   \n");
			printf(" *********           *********\n");
			printf("************       ************\n");
			printf("*************     **************\n");
			printf("**************   ***************\n");
			printf("*************** ***************\n");
			printf(" *******    *** ***    *******\n");
			printf("  ******     *****     ******\n");
			printf("   ******     ***     ******\n");
			printf("     ******    *     ******\n");
			printf("       ******  *   ******\n");
			printf("         **************\n");
			printf("           **********\n");
			printf("             ******\n");
			printf("               ***\n");
			printf("                *\n");
			printf("mua!\n");
			printf("Loving you is the important thing, Miss Lester.\n");
			printf("There are some people who think ");
			printf("love is sex and marriage and six o��clock - kisses and children,");
			printf("and perhaps it is, Miss Lester.");
			printf("But do you know what I think ?");
			printf("I think love is a touch and yet not a touch.");
			Sleep(888);
			flag = 0;                     /*�˳�*/
			break;
		}
	}
	p = qu->front;  //���ٶ���
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
}

int main()
{
	SeeDoctor();
	return 0;
}
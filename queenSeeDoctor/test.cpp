#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <Windows.h>

typedef struct qnode
{
	int data;
	struct qnode *next;
} QNode;            /*链队结点类型*/

typedef struct
{
	QNode *front, *rear;
} QuType;           /*链队类型*/

void SeeDoctor()
{
	int sel, flag = 1, find, no;
	QuType *qu;
	QNode *p;
	QNode *q;
	qu = (QuType *)malloc(sizeof(QuType));    /*创建空队*/
	qu->front = qu->rear = NULL;
	while (flag == 1)                             /*循环执行*/
	{
		//printf("1:排队 2:就诊 3:查看排队 4.不再排队,余下依次就诊 5:下班  请选择:");
		printf("\n\n%20s==============================", " ");
		printf("\n%25s1.排队", " ");
		printf("\n%25s2.就诊", " ");
		printf("\n%25s3.查看排队", " ");
		printf("\n%25s4.不再排队，余下一次就诊", " ");
		printf("\n%25s5.下班", " ");
		printf("\n\n%20s==============================", " ");
		printf("\n请选择(0-8)：");
		scanf("%d", &sel);
		switch (sel)
		{
		case 1:
			printf("  >>输入病历号:");
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
					printf("  >>输入的病历号重复,重新输入:");
			} while (find == 1);
			p = (QNode *)malloc(sizeof(QNode));   /*创建结点*/
			p->data = no;
			p->next = NULL;
			if (qu->rear == NULL)                 /*第一个病人排队*/
			{
				qu->front = qu->rear = p;
			}
			else
			{
				qu->rear->next = p;
				qu->rear = p; /*将*p结点入队*/
			}
			break;
		case 2:
			if (qu->front == NULL)                /*队空*/
				printf("  >>没有排队的病人!\n");
			else                                /*队不空*/
			{
				p = qu->front;
				printf("  >>病人%d就诊\n", p->data);
				if (qu->rear == p)            /*只有一个病人排队的情况*/
				{
					qu->front = qu->rear = NULL;
				}
				else
					qu->front = p->next;
				free(p);
			}
			break;
		case 3:
			if (qu->front == NULL)            /*队空*/
				printf("  >>没有排列的病人!\n");
			else                            /*队不空*/
			{
				p = qu->front;
				printf("  >>排队病人:");
				while (p != NULL)
				{
					printf("%d ", p->data);
					p = p->next;
				}
				printf("\n");
			}
			break;
		case 4:
			if (qu->front == NULL)            /*队空*/
				printf("  >>没有排列的病人!\n");
			else                            /*队不空*/
			{
				p = qu->front;
				printf("  >>病人按以下顺序就诊:");
				while (p != NULL)
				{
					printf("%d ", p->data);
					p = p->next;
				}
				printf("\n");
			}
			flag = 0;                         /*退出*/
			break;
		case 5:
			if (qu->front != NULL)            /*队不空*/
				printf("  >>请排队的病人明天就医!\n");
			printf("本医院即将关闭");
			printf("      多谢！有缘江湖再见！");
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
			printf("love is sex and marriage and six o’clock - kisses and children,");
			printf("and perhaps it is, Miss Lester.");
			printf("But do you know what I think ?");
			printf("I think love is a touch and yet not a touch.");
			Sleep(888);
			flag = 0;                     /*退出*/
			break;
		}
	}
	p = qu->front;  //销毁队列
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
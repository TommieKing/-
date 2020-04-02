#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int n;

DuLinkedList creat_DuL()    //定义建立链表的函数
{
	n = 0;
	DuLinkedList p1, p2, head;
	p1 = p2 = (DuLinkedList)malloc(sizeof(DuLNode));   //malloc分配动态内存
	printf("请输入内容以0结束(不包括0)：");
	scanf("%d", &p1->data);
	head = NULL;   //分配头指针为空
	while (p1->data != 0)
	{
		++n;
		if (n == 1)
		{
			head = p1;
			p1->prior = NULL;
		}
		else
		{
			p2->next = p1->data;
			p1->prior = p2->data;
		}
		p2 = p1;
		p1 = (DuLinkedList)malloc(sizeof(DuLNode));   //开辟新的动态内存
		scanf("%d", &p1->data);
	};
	p2->next = NULL;
	return (head);   //返回链表头地址
};

void print_DuL(DuLinkedList head)   //输出函数
{
	DuLinkedList p;
	printf("链表为：\n");
	p = head;
	if (head != NULL)
	{
		do
		{
			printf("%d\n", p->data);
			p = p->next;
		} while (p != NULL);
	}
}
DuLNode* ListLocate(DuLNode* ptr, ElemType position)//查找第position个节点
{
	ElemType i;
	DuLNode* cursor = ptr;
	for (i = 1; i < position; ++i)
		cursor = cursor->next;
	return cursor;
}
int main(void)
{
	int a,b,c,s;
	DuLinkedList pt;
	DuLNode* p;
	DuLNode* q;
	ElemType* e;
	void print_data(ElemType e);
	while (1)
	{
		printf("******请输入您的选择******\n");
		printf("******1.创建一个链表******\n");
		printf("******2.输出链表内容******\n");
		printf("******3.初始化空链表******\n");
		printf("******4.销毁链表释放节点******\n");
		printf("******5.在节点p之前插入节点q******\n");
		printf("******6.在节点p之后插入节点q******\n");
		printf("******7.删除节点p之后的第一个节点并将其值赋给e******\n");
		scanf("%d", &s);

		switch (s)
		{
		case 1:
			pt = creat_DuL();//调用建立链表的函数
			break;
		case 2:
			print_DuL(pt);   //调用输出链表的函数
			break;
		case 3:
			InitList_DuL(&pt);
			break;
		case 4:
			DestroyList_DuL(&pt);//销毁链表释放节点
			break;	
		case 5:
			printf("p为第几个节点：");
			scanf("%d", &c);

			p = ListLocate(pt, c);
			InsertBeforeList_DuL(&p, &q);// 在节点p之前插入节点q
				break;
		case 6:
			printf("p为第几个节点：");
			scanf("%d", &b);

			p = ListLocate(pt, b);
			InsertAfterList_DuL(&p, &q); //在节点p之后插入节点q
			break;
		case 7:
			printf("请输入e：\n");
			scanf("%d", &a);
			DeleteList_DuL(&p, &e);//删除节点p之后的第一个节点并将其值赋给e
			break;
	

		}
		system("pause");
		system("cls");

	}
	system("pause");
	system("cls");
	return 0;
}
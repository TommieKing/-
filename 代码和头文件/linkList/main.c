//用于引用和测试代码块
#include <stdio.h>
#include<stdlib.h>
#include "../head/linkedList.h"

int n;


LinkedList creat()    //定义建立链表的函数
{
	n = 0;
	LinkedList p1,  p2,  head;
	p1 = p2 = (LinkedList)malloc(sizeof(LNode));   //malloc分配动态内存
	printf("请输入内容以0结束(不包括0)：");
	scanf("%d", &p1->data);                                    
	head = NULL;   //分配头指针为空
	while (p1->data != 0)
	{
		++n;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (LinkedList)malloc(sizeof(LNode));   //开辟新的动态内存
		scanf("%d", &p1->data);
	};
	p2->next = NULL;
	return (head);   //返回链表头地址
};

void print(LinkedList head)   //输出函数
{
	LinkedList p;
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

LNode* ListLocate(LNode* ptr, ElemType position)//查找第position个节点
{
	ElemType i;
	LNode* cursor = ptr;
	for (i = 1; i < position; ++i)
		cursor = cursor->next;
	return cursor;
}

int main(void)
{
	int a,b,c,s;
	LinkedList pt;
	LNode* p;
	LNode* q;
	ElemType* e;
	void print_data(ElemType e);
	while(1)
	{
	printf("******请输入您的选择******\n");
	printf("******1.创建一个链表******\n");
	printf("******2.输出链表内容******\n");
	printf("******3.初始化空链表******\n");
	printf("******4.销毁链表释放节点******\n");
	printf("******5.p在节点p之后插入节点q******\n");
	printf("******6.删除节点p之后的第一个节点并将其值赋给e******\n");
	printf("******7.遍历链表并调用函数访问******\n");
	printf("******8.根据e查找链表中的第一个节点******\n");
	printf("******9.反转链接列表******\n");
	printf("******10.判断链表是否循环******\n");
	printf("******11.倒转链表中偶数节点******\n");
	printf("******12.在链接列表中查找中间节点******\n");
	scanf("%d", &s);
	


		switch (s)
		{
		case 1:
			pt = creat();//调用建立链表的函数
			break;
		case 2:
			print(pt);   //调用输出链表的函数
			break;
		case 3:
			InitList(&pt);
			break;
		case 4:
			DestroyList(&pt);//销毁链表释放节点
			break;
		case 5:
			printf("p为第几个节点：");
			scanf("%d",&b);

			p = ListLocate(pt, b);
			InsertList(&p, &q); //在节点p之后插入节点q
			break;
		case 6:
			printf("p为第几个节点：");
			scanf("%d", &c);

			p = ListLocate(pt, c);
			DeleteList(&p, &e);//删除节点p之后的第一个节点并将其值赋给e
			break;
		case 7:
			TraverseList(pt, &print_data);// 遍历链表并调用函数访问
			break;
		case 8:
			printf("请输入e：\n");
			scanf("%d", &a);
			SearchList(pt, a);//根据e查找链表中的第一个节点
			break;
		case 9:
			ReverseList(&pt);//反转链接列表
			break;
		case 10:
			IsLoopList(pt);//判断链表是否循环
			break;
		case 11:
			ReverseEvenList(pt);//倒转链表偶数节点
			break;
		case 12:
			FindMidNode(&pt);//在链接列表中查找中间节点
			break;
		default:
			printf("error");
			break;

		}
		system("pause");
		system("cls");
		
	}
	system("pause");
	system("cls"); 
	return 0;
}


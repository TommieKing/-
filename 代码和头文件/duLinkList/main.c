#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int n;

DuLinkedList creat_DuL()    //���彨������ĺ���
{
	n = 0;
	DuLinkedList p1, p2, head;
	p1 = p2 = (DuLinkedList)malloc(sizeof(DuLNode));   //malloc���䶯̬�ڴ�
	printf("������������0����(������0)��");
	scanf("%d", &p1->data);
	head = NULL;   //����ͷָ��Ϊ��
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
		p1 = (DuLinkedList)malloc(sizeof(DuLNode));   //�����µĶ�̬�ڴ�
		scanf("%d", &p1->data);
	};
	p2->next = NULL;
	return (head);   //��������ͷ��ַ
};

void print_DuL(DuLinkedList head)   //�������
{
	DuLinkedList p;
	printf("����Ϊ��\n");
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
DuLNode* ListLocate(DuLNode* ptr, ElemType position)//���ҵ�position���ڵ�
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
		printf("******����������ѡ��******\n");
		printf("******1.����һ������******\n");
		printf("******2.�����������******\n");
		printf("******3.��ʼ��������******\n");
		printf("******4.���������ͷŽڵ�******\n");
		printf("******5.�ڽڵ�p֮ǰ����ڵ�q******\n");
		printf("******6.�ڽڵ�p֮�����ڵ�q******\n");
		printf("******7.ɾ���ڵ�p֮��ĵ�һ���ڵ㲢����ֵ����e******\n");
		scanf("%d", &s);

		switch (s)
		{
		case 1:
			pt = creat_DuL();//���ý�������ĺ���
			break;
		case 2:
			print_DuL(pt);   //�����������ĺ���
			break;
		case 3:
			InitList_DuL(&pt);
			break;
		case 4:
			DestroyList_DuL(&pt);//���������ͷŽڵ�
			break;	
		case 5:
			printf("pΪ�ڼ����ڵ㣺");
			scanf("%d", &c);

			p = ListLocate(pt, c);
			InsertBeforeList_DuL(&p, &q);// �ڽڵ�p֮ǰ����ڵ�q
				break;
		case 6:
			printf("pΪ�ڼ����ڵ㣺");
			scanf("%d", &b);

			p = ListLocate(pt, b);
			InsertAfterList_DuL(&p, &q); //�ڽڵ�p֮�����ڵ�q
			break;
		case 7:
			printf("������e��\n");
			scanf("%d", &a);
			DeleteList_DuL(&p, &e);//ɾ���ڵ�p֮��ĵ�һ���ڵ㲢����ֵ����e
			break;
	

		}
		system("pause");
		system("cls");

	}
	system("pause");
	system("cls");
	return 0;
}
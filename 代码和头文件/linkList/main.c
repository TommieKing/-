//�������úͲ��Դ����
#include <stdio.h>
#include<stdlib.h>
#include "../head/linkedList.h"

int n;


LinkedList creat()    //���彨������ĺ���
{
	n = 0;
	LinkedList p1,  p2,  head;
	p1 = p2 = (LinkedList)malloc(sizeof(LNode));   //malloc���䶯̬�ڴ�
	printf("������������0����(������0)��");
	scanf("%d", &p1->data);                                    
	head = NULL;   //����ͷָ��Ϊ��
	while (p1->data != 0)
	{
		++n;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (LinkedList)malloc(sizeof(LNode));   //�����µĶ�̬�ڴ�
		scanf("%d", &p1->data);
	};
	p2->next = NULL;
	return (head);   //��������ͷ��ַ
};

void print(LinkedList head)   //�������
{
	LinkedList p;
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

LNode* ListLocate(LNode* ptr, ElemType position)//���ҵ�position���ڵ�
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
	printf("******����������ѡ��******\n");
	printf("******1.����һ������******\n");
	printf("******2.�����������******\n");
	printf("******3.��ʼ��������******\n");
	printf("******4.���������ͷŽڵ�******\n");
	printf("******5.p�ڽڵ�p֮�����ڵ�q******\n");
	printf("******6.ɾ���ڵ�p֮��ĵ�һ���ڵ㲢����ֵ����e******\n");
	printf("******7.�����������ú�������******\n");
	printf("******8.����e���������еĵ�һ���ڵ�******\n");
	printf("******9.��ת�����б�******\n");
	printf("******10.�ж������Ƿ�ѭ��******\n");
	printf("******11.��ת������ż���ڵ�******\n");
	printf("******12.�������б��в����м�ڵ�******\n");
	scanf("%d", &s);
	


		switch (s)
		{
		case 1:
			pt = creat();//���ý�������ĺ���
			break;
		case 2:
			print(pt);   //�����������ĺ���
			break;
		case 3:
			InitList(&pt);
			break;
		case 4:
			DestroyList(&pt);//���������ͷŽڵ�
			break;
		case 5:
			printf("pΪ�ڼ����ڵ㣺");
			scanf("%d",&b);

			p = ListLocate(pt, b);
			InsertList(&p, &q); //�ڽڵ�p֮�����ڵ�q
			break;
		case 6:
			printf("pΪ�ڼ����ڵ㣺");
			scanf("%d", &c);

			p = ListLocate(pt, c);
			DeleteList(&p, &e);//ɾ���ڵ�p֮��ĵ�һ���ڵ㲢����ֵ����e
			break;
		case 7:
			TraverseList(pt, &print_data);// �����������ú�������
			break;
		case 8:
			printf("������e��\n");
			scanf("%d", &a);
			SearchList(pt, a);//����e���������еĵ�һ���ڵ�
			break;
		case 9:
			ReverseList(&pt);//��ת�����б�
			break;
		case 10:
			IsLoopList(pt);//�ж������Ƿ�ѭ��
			break;
		case 11:
			ReverseEvenList(pt);//��ת����ż���ڵ�
			break;
		case 12:
			FindMidNode(&pt);//�������б��в����м�ڵ�
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


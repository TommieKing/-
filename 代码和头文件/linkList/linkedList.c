#include "../head/linkedList.h"
//�ӿں�����ʵ��
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 ��ʹ��û��ֵ��ͷ�ڵ��ʼ��������
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) 
{
    if ((*L = (LinkedList*)malloc(sizeof(LNode))) == NULL)//�ж��Ƿ�Ϊ������
    {
        exit(1);
    }
    (*L)->next = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes���������ͷŽڵ�
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LNode* p = *L, * q;

    while (p != NULL)//�ж�p�Ƿ�Ϊ�� 
    {
        q = p;//����p�ĵ�ַ
        p = p->next;//pָ����һ���ڵ�
        free(q);//�ͷ�ԭ��p�ĵ�ַ
    }

    *L = NULL;//����L �ĵ�ַ��ֵΪ��
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p�ڽڵ�p֮�����ڵ�q
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q)
{

    q->next = p->next;//qָ��p����һ��
    p->next = q;//pָ��q
    return SUCCESS;

}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 ɾ���ڵ�p֮��ĵ�һ���ڵ㲢����ֵ����e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) 
{
   
    if (p->next == NULL)//�ж�p�ǲ������һ��
    {
        return ERROR;
    }
    else
    {
        e=p->next;//�ڵ�p֮��ĵ�һ���ڵ㲢����ֵ����e
        p->next =p->next->next; //ɾ��p�ĺ�һ���ڵ�
        return SUCCESS;

    }

}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 �����������ú�������
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
    LinkedList q;//����ṹ��ָ��
    q = L;
    if (q != NULL)//�ж��Ƿ�Ϊ��
    {
        while (q != NULL)
        {
            (*visit)(q->data);//��data���
            q = q->next;//ȡ��һ���ڵ�
        }
    }
    else
    {
        printf("������Ϊ��");
    }
}
void print_data(ElemType e)
{
    printf("%d\n", e);//��ӡ����
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 ����e���������еĵ�һ���ڵ�
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    while (L != NULL)//�ж��Ƿ�Ϊ��
    {
        if (e == L->data)//�ж��Ƿ�Ϊe
        {
            printf("�ҵ���\n");
            
            return SUCCESS;
        }

        L = L->next;//ȡ��һ���ڵ�
    }
    //û�ҵ�
    printf("û�ҵ�");
    return ERROR;
        
    
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list��ת�����б�
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L) {

    if (!(*L) && !(*L)->next)//�ж��޽���ֻ��һ���������
        return ERROR;
    LNode* pre, * cur, * Next;//ǰ�к�����ָ��
    pre = (*L);
    cur = (*L)->next;
    pre->next = NULL;//��һ��ָ��ָ��NULL
    while (cur)
    {
        Next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = Next;
    }
    (*L) = pre;
    return SUCCESS;
   
}



/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped�ж������Ƿ�ѭ��
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {

    LinkedList p = L;//��ָ��
    LinkedList q = L;//��ָ��
    while (p != NULL && q != NULL && q->next != NULL)//�жϿ���ָ���Ƿ�ͷ
    {
        p = p+1;
       if (p->next != NULL)//�ж���ָ����һ���Ƿ�ͷ
            q = q+2;
     
        if (p == q)
             printf("����ѭ��");
            return SUCCESS;
    

    }
    printf("û�гɻ�");
    return ERROR;

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list�������б��в����м�ڵ�
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L)
{
    int n;
    LinkedList slow = *L, fast = (*L)->next;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
 //       n = (slow->data);
        printf("�м�ڵ���%d",(*slow).data);
        return slow;
    

}


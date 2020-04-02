#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L)
{
   
    if (*L ==NULL )//�ж��Ƿ�Ϊ�� 
    {
            exit(1);
        }
    *L = (DuLinkedList*)malloc(sizeof(DuLNode));//���䶯̬�ڴ�
    (*L)->next = (*L)->prior = NULL;//��ʼ��ǰ�������
    return SUCCESS;
    
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L)
{
    DuLinkedList q, p = (*L)->next; // pָ���һ����� 
    while (p != *L) // pû����ͷ 
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(*L);
    *L = NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) 
{
    q->prior = p->prior;//��q��ǰ��ָ��p��ǰ��
    p->prior->next = q;//��p��ǰ���ĺ��ָ��q
    q->next = p;//��q�ĺ��ָ��p
    p->prior = q;//��p��ǰ��ָ��q
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    q->next = p->next;//��q�ĺ��ָ��p�ĺ��
    p->next->prior = q;//��p�ĺ�̵�ǰ��ָ��q
    q->prior = p;//��q��ǰ��ָ��p
    p->next = q;//��p�ĺ��ָ��q
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 ɾ���ڵ�p֮��ĵ�һ���ڵ㲢����ֵ����e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    DuLNode* q;
    if (p->next == NULL)
    {
        return ERROR;
    }
    else
    {
        
        e = p->next;
        p->next = p->next->next;
        free(q);
        return SUCCESS;

    }
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLinkedList q;
    q = L;
    if (q != NULL)
    {
        while (q != NULL)
        {
            (*visit)(q->data);
            q = q->next;
          
        }
    }
    else
    {
        printf("������Ϊ��");
    }
}
void print_data(ElemType e)
{
    printf("%d\n", e);
}
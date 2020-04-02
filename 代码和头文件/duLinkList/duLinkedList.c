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
   
    if (*L ==NULL )//判断是否为空 
    {
            exit(1);
        }
    *L = (DuLinkedList*)malloc(sizeof(DuLNode));//分配动态内存
    (*L)->next = (*L)->prior = NULL;//初始化前驱，后继
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
    DuLinkedList q, p = (*L)->next; // p指向第一个结点 
    while (p != *L) // p没到表头 
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
    q->prior = p->prior;//将q的前驱指向p的前驱
    p->prior->next = q;//将p的前驱的后继指向q
    q->next = p;//将q的后继指向p
    p->prior = q;//将p的前驱指向q
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
    q->next = p->next;//将q的后继指向p的后继
    p->next->prior = q;//将p的后继的前驱指向q
    q->prior = p;//将q的前驱指向p
    p->next = q;//将p的后继指向q
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 删除节点p之后的第一个节点并将其值赋给e
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
        printf("该链表为空");
    }
}
void print_data(ElemType e)
{
    printf("%d\n", e);
}
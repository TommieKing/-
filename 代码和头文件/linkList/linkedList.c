#include "../head/linkedList.h"
//接口函数的实现
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 仅使用没有值的头节点初始化空链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) 
{
    if ((*L = (LinkedList*)malloc(sizeof(LNode))) == NULL)//判断是否为空链表
    {
        exit(1);
    }
    (*L)->next = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes销毁链表释放节点
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LNode* p = *L, * q;

    while (p != NULL)//判断p是否为空 
    {
        q = p;//保存p的地址
        p = p->next;//p指向下一个节点
        free(q);//释放原先p的地址
    }

    *L = NULL;//最后把L 的地址赋值为空
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p在节点p之后插入节点q
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q)
{

    q->next = p->next;//q指向p的下一个
    p->next = q;//p指向q
    return SUCCESS;

}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 删除节点p之后的第一个节点并将其值赋给e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) 
{
   
    if (p->next == NULL)//判断p是不是最后一个
    {
        return ERROR;
    }
    else
    {
        e=p->next;//节点p之后的第一个节点并将其值赋给e
        p->next =p->next->next; //删除p的后一个节点
        return SUCCESS;

    }

}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 遍历链表并调用函数访问
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
    LinkedList q;//定义结构体指针
    q = L;
    if (q != NULL)//判断是否为空
    {
        while (q != NULL)
        {
            (*visit)(q->data);//将data输出
            q = q->next;//取下一个节点
        }
    }
    else
    {
        printf("该链表为空");
    }
}
void print_data(ElemType e)
{
    printf("%d\n", e);//打印数据
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 根据e查找链表中的第一个节点
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    while (L != NULL)//判断是否为空
    {
        if (e == L->data)//判断是否为e
        {
            printf("找到了\n");
            
            return SUCCESS;
        }

        L = L->next;//取下一个节点
    }
    //没找到
    printf("没找到");
    return ERROR;
        
    
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list反转链接列表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L) {

    if (!(*L) && !(*L)->next)//判断无结点或只有一个结点的情况
        return ERROR;
    LNode* pre, * cur, * Next;//前中后三个指针
    pre = (*L);
    cur = (*L)->next;
    pre->next = NULL;//第一个指针指向NULL
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
 *	@description : judge whether the linked list is looped判断链表是否循环
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {

    LinkedList p = L;//慢指针
    LinkedList q = L;//快指针
    while (p != NULL && q != NULL && q->next != NULL)//判断快慢指针是否到头
    {
        p = p+1;
       if (p->next != NULL)//判断慢指针下一步是否到头
            q = q+2;
     
        if (p == q)
             printf("链表循环");
            return SUCCESS;
    

    }
    printf("没有成环");
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
 *	@description : find the middle node in the linked list在链接列表中查找中间节点
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
        printf("中间节点是%d",(*slow).data);
        return slow;
    

}


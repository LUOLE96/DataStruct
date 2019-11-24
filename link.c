#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*LinkList;

LinkList Init_Link(void)
{
    LinkList node = (NODE *)malloc(sizeof(NODE));
    node->next = NULL;
    node->data = 111;
    return node;
}

/*
功能：在表L中查找第k个元素
参数：L为带头结点单链表的头指针，k为要查找的第k个元素
返回值：找到返回该元素节点的指针，否则，返回空NULL
*/
LinkList Find_List(LinkList L,int k)
{
    LinkList p;
    int i;i = 1;
    p = L->next;
    while(p && i < k){
        p = p->next;i++;
    }
    if(p && i==k){
        return p;
    }
    return NULL;
}

/*
功能：将元素elem插入表中的第k个元素之前
参数：L为带头节点单链表的头指针，k为要插入的位置(第k个元素之前),elem为要插入的元素
返回值：成功返回0，失败返回-1
 */
int Insert_List(LinkList L,int k,int elem)
{
    LinkList p,s;
    if(k == 1) p = L;
    else p = Find_List(L,k-1);
    if(!p) return -1;

    s = (NODE *)malloc(sizeof(NODE));
    if(!s)return -1;

    s->data = elem;
    s->next = p->next;
    p->next = s;
    return 0;
}


/*
功能：删除链表中第k个元素的节点
参数：L为带头结点单向链表的头指针,k为要删除的第k个元素
返回值：成功返回0，失败返回-1
*/
int Delete_List(LinkList L,int k)
{
    LinkList p,s;
    if(k == 1) p = L;
    else p = Find_List(L,k-1);

    if(!p||!p->next) return -1;
    s = p->next;
    p->next = s->next;
    free(s);
    return 0;

}

/*
功能：打印链表
参数：带头节点的链表
返回值：无
*/
void Display_List(LinkList L)
{
    LinkList p = L;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

/*
功能：查询某个数据在节点中的位置
参数：L带头结点的链表，elem要查询的数据
返回值：返回该元素在链表中的位置,失败返回-1
*/
int Select_Link(LinkList L,int elem)
{
    LinkList p = L->next;int i = 1;
    while(p != NULL){
        if(p->data == elem){
            return i;
        }
        i++;
        p = p->next;
    }
    return -1;
}


/*
功能：将链表中的数据elem更改为newelem
参数：L带头结点的链表，elem现存链表中的数据，newelem要更改成的数据
返回值：成功返回0，失败返回-1
*/
int Change_Link(LinkList L,int elem,int newelem)
{
    int add = Select_Link(L,elem);
    if(add == -1){
        printf("the data to change none exit\n");
        return -1;
    }
    LinkList p = L->next;
    int i;
    for(i=1;i<add;i++){
        p = p->next;
    }

    p->data = newelem;
    return 0;
}

int main(void)
{
    LinkList L = Init_Link();
    Insert_List(L,1,222);
    Insert_List(L,2,333);
    Insert_List(L,3,444);
    int num = Select_Link(L,222);
    printf("num = %d\n",num);

    Change_Link(L,222,666);

    Delete_List(L,1);

    Display_List(L);

}

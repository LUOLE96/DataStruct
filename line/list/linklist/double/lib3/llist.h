#ifndef LLIST_H__
#define LLIST_H__

#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2
typedef void llist_op(const void *);
typedef int llist_cmp(const void *,const void *);

//变长结构体
struct llist_node_st
{
    struct llist_node_st *prev;
    struct llist_node_st *next;
    char data[0];//c99才支持
};

//加入面向对象思想，把函数做成函数指针
typedef struct llist_head_st
{
    int size;
    struct llist_node_st head;
    int (*insert)(struct llist_head_st *,const void *,int);
    void *(*find)(struct llist_head_st *,const void *,llist_cmp *);
    int (*delete)(struct llist_head_st *,const void *,llist_cmp *);
    int (*fetch)(struct llist_head_st *,const void *,llist_cmp *,void *);
    void (*traval)(struct llist_head_st *,llist_op *);
    void (*destroy)(struct llist_head_st *);
}LLIST;

LLIST *llist_create(int initsize);
#endif
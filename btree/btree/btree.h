#ifndef BTREE_H
#define BTREE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//二叉树，如果是数组存储，已知某下标为n,则左子树和右子树的下标为 2 * n + 1,2 * n + 2 
//先序遍历：根左右
//中序遍历：左根右
//后序遍历：左右根
//set: 有序二叉树,不允许有重复值

#define SYSERR(x,option,y,message,z)       if((x) option (y)) \
                                           {\
                                               printf("%s %s %d error : %s\n",__FILE__,__func__,__LINE__,message);\
                                               return z;\
                                           }

typedef struct btree
{
    struct btree *lchild;
    void *data;
    struct btree *rchild;
}btree_t;

btree_t *create_btree();//创建二叉树

typedef int (*cmpfun_t)(const void *,const void *);
int insert_btree(btree_t **root,const void *data,int size,cmpfun_t cmpfun);////向二叉树中插入数据，有序插入，不可重复

typedef void (*showfun_t)(const void *);
void first_show(btree_t *root,showfun_t showfun);	//先序遍历
void mid_show(btree_t *root,showfun_t showfun);		//中序遍历
void last_show(btree_t *root,showfun_t showfun);	//后序遍历

btree_t *find_min(btree_t *root);	//查找最小节点
btree_t *find_max(btree_t *root);	//查找最大节点
btree_t *find_vbtree(btree_t *root,const void *data,cmpfun_t cmpfun);	//按值查找

//注意：因为数据类型是void *,不能定义修改函数,所以需要用户定义：先按值查找，再修改(只能修改非主键)
//如果直接修改主键，则可能造成有序树变成无序树,所以不能直接修改主键：应该先删除，再插入,或者修改之后必须重新排序

int delete_vbtree(btree_t **root,const void *data,cmpfun_t cmpfun);		//按值删除

#endif // !BTREE_H



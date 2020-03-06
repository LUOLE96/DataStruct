#include "btree.h"

btree_t *create_btree()//因为二叉树的根节点允许为空，所以
{
    btree_t *root = NULL;
    return root;
}

int insert_btree(btree_t **root,const void *data,int size,cmpfun_t cmpfun)
{
    SYSERR(NULL,==,data,"data is null",-1);
    SYSERR(size,<,1,"size must >= 1",-1);

    btree_t *newnode = NULL;
    if(NULL == *root){
        newnode = malloc(sizeof(btree_t));
        SYSERR(NULL,==,newnode,"malloc error",-1);
        newnode->lchild = newnode->rchild = NULL;
        newnode->data = malloc(size);

        SYSERR(NULL,==,newnode->data,"malloc error",-1);
        memcpy(newnode->data,data,size);

        *root = newnode;
        return 0;
    }

    if(cmpfun(data,(*root)->data) < 0)
        return insert_btree(&(*root)->lchild,data,size,cmpfun);
    else if(cmpfun(data,(*root)->data) > 0)
        return insert_btree(&(*root)->rchild,data,size,cmpfun);
    else
        return -1;

    return -1;
}

void first_show(btree_t *root,showfun_t showfun)
{
    if(NULL == root){
        return ;
    }
    showfun(root->data);
    first_show(root->lchild,showfun);
    first_show(root->rchild,showfun);
}

void mid_show(btree_t *root,showfun_t showfun)
{
    if(NULL == root)
        return ;
    mid_show(root->lchild,showfun);
    showfun(root->data);
    mid_show(root->rchild,showfun);
}

void last_show(btree_t *root,showfun_t showfun)
{
    if(NULL == root)
        return ;
    
    last_show(root->lchild,showfun);
    last_show(root->rchild,showfun);
    showfun(root->data);
}

btree_t *find_max(btree_t *root)
{
    if(NULL == root)
        return NULL;
    btree_t *temp = root;
    while(temp->rchild !=  NULL)//找右子数的叶子结点
        temp = temp->rchild;
    return temp;
}

btree_t *find_min(btree_t *root)
{
    if(NULL == root)
        return NULL;
    btree_t *temp = root;
    while(temp->lchild != NULL)
        temp = temp->lchild;//找左子树结点
    
    return temp;
}

btree_t *find_vbtree(btree_t *root,const void *data,cmpfun_t cmpfun)
{
    if(NULL == root)
        return NULL;
    SYSERR(NULL,==,data,"data is null",NULL);
    if(!cmpfun(data,root->data))//找到指定值
        return root;
    else if(cmpfun(data,root->data) < 0)//如果要查找的数据比结点数据小
        return find_vbtree(root->lchild,data,cmpfun);//从左子树查找
    else//如果要查找的数据比结点大
        return find_vbtree(root->rchild,data,cmpfun);//从右子树查找

    return NULL;
}

static btree_t *connect_btree(btree_t *lchild,btree_t *rchild)
{
    if(NULL == lchild && NULL == rchild)
        return NULL;
    else if(NULL != lchild && NULL == rchild)
        return lchild;
    else if(NULL == lchild && NULL != rchild)
        return rchild;

    find_min(rchild)->lchild = lchild;//把左子树连接到右子树的左边
    //2) find_max(lchild)->rchild = rchild;  return lchild;	把右子树连接到左子树最大树的右边
	return rchild;
}

int delete_vbtree(btree_t **root,const void *data,cmpfun_t cmpfun)
{
    if(NULL == *root)
        return -1;
    SYSERR(NULL,==,data,"data is null",-1);
    btree_t *parent = *root,*current = *root,*lchild,*rchild;

    if(!cmpfun(data,(*root)->data))//如果删除的是根结点
    {
        lchild = (*root)->lchild;//保存左右子数
        rchild = (*root)->rchild;
        free((*root)->data);
        free((*root));
        *root = connect_btree(lchild,rchild);//修改根为连接后的子树
        return 0;
    }

    int flag = 0;////0表示从父点的左边找到，1表示从父节点的右边找到
    while(current != NULL)//如果删除的是中间节点
    {
        if(cmpfun(data,current->data) < 0){//如果要查找的数据比节点数据小，从节点的左边查找
            parent = current;
            current = current->lchild;
            flag = 0;
        }
        else if(cmpfun(data,current->data) > 0)//从结点的右边查找
        {
            parent = current;
            current = current->rchild;
            flag = 1;
        }
        else //如果找到
            break;
    }
    SYSERR(NULL,==,current,"at tree end!not found",-1);
    lchild = current->lchild;//保存左右子树
    rchild = current->rchild;
    free(current->data);
    free(current);

    if(!flag)////如果是从父节点左边找到
        parent->lchild = connect_btree(lchild,rchild);//连接到父节点的左边
    else			//如果是从父节点右边找到
		parent->rchild = connect_btree(lchild,rchild);	//连接到父节点的右边

	return 0;
}
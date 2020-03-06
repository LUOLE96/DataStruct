#include "btree.h"

int cmpint(const void *data1,const void *data2)
{
    const int *p1 = (const int *)data1;
    const int *p2 = (const int *)data2;
    return *p1 - *p2;
}

void showint(const void *data)
{
    const int *p = (const int *)data;
    printf("%d\t",*p);
}

int main(void)
{
    btree_t *root = create_btree();
    printf("root = %p\n",root);

    int arr[9] = {5,8,3,7,1,9,4,6,5},i,res;
    for(i = 0;i < 9;i++){
        res = insert_btree(&root,arr + i,sizeof(arr[0]),cmpint);
        printf("insert_btree res = %d\n",res);
    }
	printf("-------------先序------------------\n");
	first_show(root,showint);	//5 3 1 4 8 7 6 9
	printf("\n");
	printf("-------------中序------------------\n");
	mid_show(root,showint);		//1 3 4 5 6 7 8 9
	printf("\n");
	printf("-------------后序------------------\n");
	last_show(root,showint);	//1 4 3 6 7 9 8 5
	printf("\n");

	printf("------------查找------------------\n");

    btree_t *min = find_min(root);
	if(min != NULL)
	{
		printf("find_min res : ");
		showint(min->data);
		printf("\n");
	}

	btree_t *max = find_max(root);
	if(max != NULL)
	{
		printf("find_max res : ");
		showint(max->data);
		printf("\n");
	}

	int dest = 99;
	btree_t *result = find_vbtree(root,&dest,cmpint);
	if(NULL != result)
	{
		printf("found : result = %p\n",result);
		showint(result->data);
		printf("\n");
	}
	
	printf("------------删除------------------\n");
	int data = 5;
	delete_vbtree(&root,&data,cmpint);
	mid_show(root,showint);
	printf("\n");

	printf("------------修改----------------------\n");
	//把5修改成55
	delete_vbtree(&root,&data,cmpint);
	int newdata = 55;
	insert_btree(&root,&newdata,sizeof(newdata),cmpint);
	mid_show(root,showint);

}
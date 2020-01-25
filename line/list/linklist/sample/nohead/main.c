#include <stdio.h>
#include <stdlib.h>
#include "nohead.h"

int main()
{
    int i;
    struct node_st *list = NULL;
    struct score_st tmp;

    for(i = 0;i < 7;i++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"stu%d",i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;

        int ret = list_insert(&list,&tmp);
        if(ret != 0)
            exit(1);
    }

    list_show(list);

    //list_delete(&list);
    printf("\n");
    //list_show(list);

    int id = 1;
    struct score_st *ptr;

    ptr = list_find(list,id);
    if(ptr == NULL)
        printf("Can not find\n");
    else
        printf("%d %s %d %d\n",ptr->id,ptr->name,ptr->chinese,ptr->math);
    
    list_destroy(list);

    exit(0);
}
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void)
{
    int i;
    list *l;
    int arr[] = {12,2,23,34,9,45,56,67};

    l = list_create();
    if(l == NULL){
        printf("%d\n",__LINE__);
        exit(1); 
    }
        
    for(i = 0;i < sizeof(arr)/sizeof(*arr);i++)
    {
        //if(list_insert_at(l,0,&arr[i]))
        if(list_order_insert(l,&arr[i]))
            exit(1);
    }

    list_display(l);

    int value = 12;

    //list_delete(l,&value);

    //list_display(l);

    datatype value1;
 
    int err = list_delete_at(l,2,&value1);
    if(err)
        exit(1);
    list_display(l);
    printf("delete : %d\n",value1);

    list_destory(l);

    exit(0);
}
#include "sqstack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    datatype arr[] = {19,23,45,67};
    sqstack *st;
    st = st_create();
    if(st == NULL)
        exit(1);

    for(i = 0;i < sizeof(arr)/sizeof(*arr);i++)
        st_push(st,&arr[i]);

    st_travel(st);

    datatype tmp;
    while(st_pop(st,&tmp) == 0){
        printf("POP : %d\n",tmp);
    }


    st_destroy(st);

    exit(0);
}
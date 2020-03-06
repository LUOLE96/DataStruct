#include<stdio.h>
#include<stdlib.h>
 
char* myMalloc(){
     char *s=(char*)malloc(100);
     return s;
}
 
int main()
{
     char  *p=NULL;
     p=myMalloc();
     if(p==NULL)
        printf("P is not changed!\n");
     else{
        printf("P has been changed\n");
        free(p);
     }
     return 0;
}
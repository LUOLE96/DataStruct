#include <stdio.h>
#include <stdlib.h>

void myMalloc(char **s){
    *s = (char *)malloc(100);
}

int main(void){
    char *p = NULL;
    myMalloc(&p);
    if(p == NULL){
        printf("p is not changed!|n");
    }
    else
    {
        printf("p has been changed!\n");
        free(p);
    }
    return 0;
}
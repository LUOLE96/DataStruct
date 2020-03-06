#include <stdio.h>

void fun(int **p){
    int b = 100;
    *p = &b;
}

int main(void){
    int a = 10;
    int *q;
    q = &a;
    printf("%d\n",*q);
    fun(&q);
    printf("%d\n",*q);
    return 0;
}
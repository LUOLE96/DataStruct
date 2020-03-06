#include <stdio.h>

void fun(int *p){
	int b = 100;
	p = &b;
	printf("&p : %p\n",p);
} 

int main(void){
	int a = 10;
	int *q;
	q = &a;
	printf("&q : %p\n",q);
	printf("%d\n",*q);
	fun(q);
	printf("%d\n",*q); 
	return 0;

} 
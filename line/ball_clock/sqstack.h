#ifndef __SQSTACK_H_
#define __SQSTACK_H_

#define SIZE 5
#define type int

typedef struct
{
    type data[SIZE];
    int top;
}sqstack;

sqstack *st_create(void);

int st_isempty(sqstack *);

int st_push(sqstack *,type *);

int st_pop(sqstack *,type *);

int st_top(sqstack *,type *);

void st_travel(sqstack *);

void st_destroy(sqstack *);


#endif
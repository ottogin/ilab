#ifndef STACK_H
#define STACK_H

typedef int Data;

struct Stack {
    int n;
    int size;
    Data * a; 
};

struct Stack * stack_create(int size);
void stack_push(struct Stack * s, Data x);
Data stack_pop(struct Stack * s);
Data stack_get(struct Stack * s);
void stack_print(struct Stack * s);
int  stack_size(struct Stack * s);
int  stack_is_empty(struct Stack * s);
void stack_clear(struct Stack * s);
void stack_destroy(struct Stack * s);

#endif 

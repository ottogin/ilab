#ifndef STACK_C
#define STACK_C

#include "stack.h"
#include "error.c"
#include <stdio.h>
#include <stdlib.h>

struct Stack* stack_create(int size)
{
	struct Stack* s = malloc(sizeof(struct Stack));
	s->a = malloc(sizeof(Data) * size);
	s->size = size;
	s->n = 0;
	return s;
}

char stack_ok(struct Stack* s)
{
	if(s->n > s->size) return 0;
	if(s == NULL) return 0;
	if(s->a == NULL) return 0;
	return 1;
}

void stack_dump(struct Stack* s)
{
	printf("\n\n/////////// TREE DUMP //////////\n\n");
	if(s == NULL)
		printf("Bad pointer to the stack");
	else
	{
		printf(" size: %d reserved: %d pointer: %p \n", s->n, s->size, s->a);
		for(int i = 0; i < s->n; i++)
		{
			printf("( %d )", s->a[i]);
		}
	}
	printf("\n////////////////////////////////\n\n");
}

void stack_push(struct Stack * s, Data x)
{
	if(s->n == s->size)
	{
		s->a = realloc(s->a, 2 * sizeof(Data) *  s->size);
		s->size = s->size * 2;
	}
	s->a[s->n] = x;
	s->n = s->n + 1;
	return;
}

Data stack_pop(struct Stack * s)
{
	if(s->n == 0)
		return 0;
	Data a = s->a[s->n - 1];
	s->n = s->n - 1;
	return a;
}

Data stack_is_empty(struct Stack *s)
{
	if(s->n == 0)
		return 1;
	return 0;
}

Data stack_get(struct Stack * s)
{
	return s->a[s->n - 1];
}

void stack_print(struct Stack * s)
{
	if (s->n == 0)
	{
		printf("Empty stack\n");
		return;
	}
	int i;
	for(i = 0; i < s->n; i++)
		printf("%d ", s->a[i]);
	printf("\n");
	return;
}

int  stack_size(struct Stack * s)
{
	return s->n;
}

void stack_clear(struct Stack * s)
{
	s->n = 0;
	return;
}

void stack_destroy(struct Stack *s)
{
	free(s->a);
	free(s);
	return;
}
#endif

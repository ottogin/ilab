#ifndef CPU_C
#define CPU_C

#include "stack.c"
#include <stdlib.h>
#include <stdio.h>
#include "CPU.h"

CPU* cpu_create()
{
	CPU* c = malloc(sizeof(CPU));
	c->stack = stack_create(10);
	c->reg = malloc(REG * sizeof(int));
	c->ram = malloc(RAM * sizeof(int));
}

void cpu_destroy(CPU* c)
{
	stack_destroy(c->stack);
	free(c->reg);
	free(c->ram);	
}

void cpu_push(CPU* c, int a)
{
	stack_push(c->stack, a);	
}

int cpu_pop(CPU* c)
{
	return stack_pop(c->stack);
}

int cpu_get(CPU* c)
{
	return stack_get(c->stack);
}

void cpu_add(CPU* c)
{
	cpu_push(c, cpu_pop(c) + cpu_pop(c));
}

void cpu_mul(CPU* c)
{
	cpu_push(c, cpu_pop(c) * cpu_pop(c));
}

void cpu_dif(CPU* c)
{
	cpu_push(c, cpu_pop(c) - cpu_pop(c));
}

void cpu_div(CPU* c)
{
	cpu_push(c, cpu_pop(c) / cpu_pop(c));
}
#endif

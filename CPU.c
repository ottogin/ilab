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

void cpu_print(CPU* c, ...)
{
	printf("\n/////////////////////////////////\n\n");
	stack_print(c->stack);
	printf("\n/////////////////////////////////\n\n");
        /*for(int i = 0; i < REG; i++)
                printf("reg%d = %d", i , с->reg[i]);
        printf("/////////////////////////////////\n");
        for(int i = 0; i <  RAM; i++)
                printf("ram%d = %d", i , c->ram[i]);
        printf("/////////////////////////////////\n");*/	
}
void cpu_push(CPU* c, int a, ...)
{
	stack_push(c->stack, a);	
}

int cpu_pop(CPU* c, ...)
{
	return stack_pop(c->stack);
}

int cpu_get(CPU* c, ...)
{
	return stack_get(c->stack);
}

void cpu_add(CPU* c, ...)
{
	cpu_push(c, cpu_pop(c) + cpu_pop(c));
}

void cpu_mul(CPU* c, ...)
{
	cpu_push(c, cpu_pop(c) * cpu_pop(c));
}

void cpu_dif(CPU* c, ...)
{
	cpu_push(c, cpu_pop(c) - cpu_pop(c));
}

void cpu_div(CPU* c, ...)
{
	cpu_push(c, cpu_pop(c) / cpu_pop(c));
}

void cpu_execute(CPU* c, char* from)
{
	if(from == NULL)        from = "cmd.bin.txt";
        FILE* input = fopen(from, "r");
        char byte;
        char* number = calloc(sizeof(char), 4);

        #define DCR(name, code, f)\
                *number = byte;\
                if(*((int*) number) == code)\
                {\
               		if (f == 1)\
                        {\
                        	fscanf(input, "%c %c %c %c", number, number + 1, number + 2, number + 3);\
                        }\
	                cpu_##name (c, *(int *)number);\
			printf("%s %d\n", #name, *(int *)number);\
			*(number + 1) = 0;\
                        *(number + 2) = 0;\
                        *(number + 3) = 0;\
                }\

	fscanf(input, "%c", &byte);
        while(byte != 0)
        {
                #include"DCR.h"
                fscanf(input, "%c", &byte);
        }
	#undef DCR
        fclose(input);
        free(number);
        return;
}
#endif

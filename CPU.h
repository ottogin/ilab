#ifndef CPU_H
#define CPU_H

#define REG 4
#define RAM 100

struct my_cpu{
	struct Stack* stack;
	int *reg;
	int *ram;  
} typedef CPU;

CPU* cpu_create();
void cpu_delete(CPU* c);
void cpu_print(CPU* c, ...);
void cpu_push(CPU* c, int a, ...);
int  cpu_pop(CPU* c, ...);
int  cpu_get(CPU* c, ...);
void cpu_add(CPU* c, ...);
void cpu_mul(CPU* c, ...);
void cpu_dif(CPU* c, ...);
void cpu_div(CPU* c, ...);

#endif

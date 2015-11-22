#include "stack.c"
#include "assembler.c"
#include "CPU.c"

int main()
{
	printf("\n\n//////////////////////////////\n\n");
	translate(NULL, NULL);
	printf("\n\n//////////////////////////////\n");
	decrypt(NULL, NULL);
	CPU* my_cpu = cpu_create();
	cpu_push(my_cpu, 1);
	cpu_push(my_cpu, 2);
	cpu_add(my_cpu);
	cpu_push(my_cpu, 4);
	cpu_mul(my_cpu);
	printf("\n///////____%d____///////\n", cpu_pop(my_cpu));
	cpu_destroy(my_cpu);
	return 0;
}

#include "stack.c"
#include "assembler.c"
#include "CPU.c"

int main()
{
	printf("\n\n//////////////////////////////\n\n\n");
	translate(NULL, NULL);
	printf("\n\n//////////////////////////////\n\n\n");
	CPU* my_cpu = cpu_create();
	cpu_execute(my_cpu, NULL);
	cpu_destroy(my_cpu);
	return 0;
}

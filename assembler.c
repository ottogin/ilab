#ifndef ASSEMBLER
#define ASSEMBLER

#include<stdio.h>
#include<string.h>
#include "error.c"

void translate(char* from, char* to)
{	
	if(from == NULL)   from = getenv("CPU_TRANSLATED_FROM");
	if(to   == NULL)   to   = getenv("CPU_TRANSLATED_TO");
	if(to == NULL)
		exit_with_error(1);
	if(from == NULL)
		exit_with_error(2);
	printf("Translating was started.\n");
	FILE* input = fopen(from, "r");
	FILE* output = fopen(to, "w");
	
	ASSERT_OK(file, input)
	ASSERT_OK(file, output)

	if(input == NULL)
		exit_with_error(3);
	if(output == NULL)
		exit_with_error(4);
	printf("Files was opened ");
	if(input == NULL)
	{
		printf("with ERROR\nExit..");
		return; 
	}
	printf("sucsesfull.\n");
	char cmd[10];
	int vallue;
	#define TRN(name, code, f) \
		if (!strcmp(cmd, #name)) \
		{ \
			fprintf(output ,"%c", code);\
			printf("Found it!\n");\
			if(f == 1)\
			{\
				fscanf(input, "%d", &vallue);\
				fprintf(output, "%c%c%c%c", vallue, *((char*)&vallue + 1), *((char*)&vallue + 2), *((char*)&vallue + 3));\
			}\
		} 
	
	while(strcmp("end!", cmd))
	{
	       	fscanf(input,"%s", cmd);
                printf("got %s loading...  ", cmd);
	       	#include "TRN.h"
	}

	ASSERT_OK(file, input)
	ASSERT_OK(file, output)	

	fprintf(output, "%c", 0);
	fclose(input);
	fclose(output);	
	return;	
}

void decrypt(char* from, char* to)
{	
	if(from == NULL)	from = getenv("cpu_decrypt_from");
	if(to == NULL)		to = getenv("cpu_decrypt_to");
	FILE* input = fopen(from, "r");
	FILE* output = fopen(to, "w");

	ASSERT_OK(file, input)
        ASSERT_OK(file, output)

	char byte; 
	printf("\nDecrypting was started.\n");
	printf("Files was opened ");
	if(input == NULL)
        {
                printf("with ERROR\nExit..");
                return;
        }
	printf("sucsesfull.\n");
	char* number = calloc(sizeof(char), 4);
	#define DCR(name, code, f)\
		*number = byte;\
		if(*((int*) number) == code)\
		{\
			printf("found %s ", #name);\
			fprintf(output ,"%s ",#name);\
			if(f == 1)\
			{\
				fscanf(input, "%c %c %c %c", number, number + 1, number + 2, number + 3);\
				fprintf(output, "%d", *((int *)number));\
				printf("and  %d", *((int *)number));\
				*(number + 1) = 0;\
				*(number + 2) = 0;\
				*(number + 3) = 0;\
			}\
			printf("\n");\
			fprintf(output, "\n");\
		}\
	
	fscanf(input, "%c", &byte);
	while(byte != 0)
	{
		#include"DCR.h"
		fscanf(input, "%c", &byte);
	}
		
	ASSERT_OK(file, input)
        ASSERT_OK(file, output)

	#undef DCR

	fprintf(output, "end!\n");
	fclose(input);
	fclose(output);
	free(number);
	return;
}   

#endif

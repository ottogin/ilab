#ifndef ASSEMBLER
#define ASSEMBLER

#include<stdio.h>

void translate(char* from, char* to)
{	
	if(from == NULL)	from = "cmd.txt";
	if(to == NULL)		to = "cmd.bin.txt";
	printf("Translating was started.\n");
	FILE* input = fopen(from, "r");
	FILE* output = fopen(to, "w");
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
	fprintf(output, "%c", 0);
	fclose(input);
	fclose(output);	
       	return;	
}

void decrypt(char* from , char* to)
{	
	if(from == NULL)	from = "cmd.bin.txt";
        if(to == NULL)		to = "cmd_translated.txt";
	FILE* input = fopen(from, "r");
	FILE* output = fopen(to, "w");
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
		
	#undef DCR

	fprintf(output, "end!\n");
	fclose(input);
	fclose(output);
	free(number);
	return;
}   

#endif

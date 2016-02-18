#ifndef	ERROR
#define ERROR 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ASSERT_OK(object, pointer)\
        if(!object##_ok (pointer))\
        {\
                object##_dump (pointer);\
                assert(!"Bad object" #pointer);\
        }           

char file_ok(FILE* this)
{
	if(this == NULL) 
		return 0;
	return 1;
}

void file_dump(FILE* this)
{
	printf("\n\n/////////// TREE DUMP //////////\n\n");
	printf("Cann't open file\n");
        printf("\n////////////////////////////////\n\n");
}

void exit_with_error(int n)
{
	#define err(number, code, ref)\
		if(number == n)\
		{\
			printf("ERROR %d : %s\n", number, ref);\
			exit(code);\
		}
	
	#include"errors.h"
}

#endif

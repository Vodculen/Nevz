#include <stdio.h>
#include <stdlib.h>


void error(int status)
{
	switch (status)
	{
		case 1: 
			printf("Too little parameters where given to compile the program\n");
			break;
		case 2:
			printf("Too many parameters where given to compile the program\n");
			break;
		
		// This should never be reached
		default: 
			printf("Unknown Error Status given, cannot provide any details\n");
			break;
	}

	exit(status);
}
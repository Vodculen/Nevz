#include "include/utils.h"


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
		case 11:
			printf("The file given was unable to be opened or found\n");
			break;
		case 12:
			printf("Unable to create or put data into the buffer\n");
			break;

		
		// This should never be reached
		default: 
			printf("Unknown Error Status given, cannot provide any details\n");
			break;
	}

	exit(status);
}
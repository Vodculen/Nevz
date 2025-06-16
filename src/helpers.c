#include "../lib/helpers.h"

/**
 * @param error The index of the error you want the program to throw.
 * 
 * @return The error that you've given it to stop the program.
 */
int errorf(const int error) 
{
	switch (error) 
	{
		case 1: 
			printf("Too little parameters were given so Nevz couldn't compile the program!\n");
			break;
		case 2:
			printf("Too many parameters were given so Nevz couldn't compile the program!\n");
			break;
		default:
			break;
	}

	manual();

	return error;
}

/**
 * Simply prints out how the user needs to format the flags to make it compile.
 */
void manual() 
{
	printf("Please follow the format to compile your program below.\n");
	printf("nevz <input.nevz> <outout.asm>\n");
}
#include <stdio.h>

// Nevz
#include "include/utils.h"
#include "include/file.h"


int main(int argc, const char** argv) 
{
	char* buffer;
	long size;

	if (argc < 2) 
	{
		error(1);
	} 
	
	if (argc > 2) 
	{
		error(2);
	}

	if (readFile(argv[1], &buffer, &size) == 1)
	{
		error(11);
	}

	if (readFile(argv[1], &buffer, &size) == 2)
	{
		error(12);
	}

	readFile(argv[1], &buffer, &size);

	printf("%s, %ld", buffer, size);


	return 0;
}
#include "include/file.h"


int readFile(const char* filepath, char** buffer, long* size)
{
	FILE* file = fopen(filepath, "r");
	*buffer = 0;
	
	if (!file)
	{
		return 1;
	}


	fseek(file, 0, SEEK_END);
	*size = ftell(file);
	fseek(file, 0, SEEK_SET);

	*buffer = malloc(*size);

	if (!*buffer)
	{
		return 2;
	}

	fread(*buffer, 1, *size, file);

	fclose(file);

	return 0;
}
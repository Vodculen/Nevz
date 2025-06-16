#include "../lib/compiler.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char *fcompile(const char *filename)
{
	FILE *file;
	char *line = NULL;
	size_t length = 0;
	size_t read;

	file = fopen(filename, "rb");

	if (filename == NULL)
	{
		printf("[File]: The given file \"%s\" couldn't be read from.\n", filename);
		exit(1);
	}

	char *buffer = (char*) calloc(1, sizeof(char));
	buffer[0] = '\0';

	while ((read = getline(&line, &length, file)) != -1) {
		buffer = (char*) realloc(buffer, (strlen(buffer) + strlen(line) + 1) * sizeof(char));
		strcat(buffer, line);
	}

	fclose(file);
	
	if (line) {
		free(line);
	}

	return buffer;
}


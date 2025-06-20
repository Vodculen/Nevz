#include "lib/compiler.h"

<<<<<<< Updated upstream
/**
 * @param argc The index of flags 
 * @param argv The diffrent flags
 * 
 * @return The exit status for the compiler
 */
int compile(int argc, const char *argv[]) {
	if (argc < 3) {
		crash(1);
	} else if (argc > 3) {
		crash(2);
	}

	return 0;
}
=======

char* readfile(const char* filename)
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
>>>>>>> Stashed changes

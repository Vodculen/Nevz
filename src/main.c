#include <stdio.h>

#include "../lib/compiler.h"


int main(int argc, char const *argv[]) 
{
	if (argc < 2)
	{
		printf("Invalid parameters: Please put the following \"nevz [filename.nevz]\"\n");
		return 1;
	}

	char* file_contents = null;

	file_contents = fcompile(argv[1]);

	void* tokenize(file_contents);

	free(file_contents);
	return 0;
}

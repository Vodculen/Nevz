#include <stdio.h>

#include "include/compiler.h"
#include "include/lexer.h"


int main(int argc, const char *argv[]) 
{
	if (argc < 2)
	{
		printf("Invalid parameters: Please put the following \"nevz [filename.nevz]\"\n");
		return 1;
	}

	char* file = readfile(argv[1]);

	LEXER* lexer = new_lexer(file);
	TOKEN* token;

	while (token -> type != TOKEN_EOF)
	{
		token = lex(lexer);
		printf("%s\n", tokenstr(token));
	}
	

	free(file);

	return 0;
}

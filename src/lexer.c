#include "../lib/lexer.h"

void *lex(const char *fcontents) 
{

	char* token = strtok(fcontents, " ");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
        printf("%s\n", token);
		TOKEN *token_struct = malloc(sizeof TOKEN);

		if (strncmp(semicolon_str, token, sizeof semicolon_str) == 0) 
		{
			token_struct -> tokens = SEMICOLON;
			token_struct -> value (char) = semicolon_str;
		} 
		else if (strncmp(return_str, token, sizeof return_str) == 0) 
		{
			token_struct -> tokens = RETURN;
			token_struct -> value (char) = return_str;
		} 
		else if (is_integer_literal(token)) 
		{
			token_struct -> tokens = INTEGER_LITERAL;
			token_struct -> value (char) = token;
		}

		// add the token struct to our list
		// but really for now, print the token struct
		print_token_struct(token_struct);

        token = strtok(NULL, " ");
    }
}


int is_integer_literal(char* input) 
{
	if (!isdigit(input)) {
		return 1;
	}

	return 0;
}

void print_token_struct(char *token_struct) 
{
	printf("TokenType: %s, TokenValue: %s", token_struct -> tokens, token_struct -> value);
}
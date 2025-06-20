#include "lib/token.h"


TOKEN* new(char value[], TOKENS token_type)
{
	TOKEN* token = malloc(sizeof(TOKEN));

	token -> type = token_type;
	token -> value = value;

	return token;
}

const char* typestr(TOKENS type)
{
	switch (type)
	{
		case TOKEN_RETURN: return "RETURN";
		case TOKEN_INTEGER_LITERAL: return "INTEGER_LITERAL";
		case TOKEN_SEMICOLON: return "SEMICOLON";
		case TOKEN_IDENTIFIER: return "IDENTIFER";
		case TOKEN_EOF: return "EOF";
	}

	return "Not Stringable";
}

char* tokenstr(TOKEN* token)
{
	const char* type = typestr(token -> type);
	const char* template = "<| Type: \"%s\", Value: \"%s\" |>";

	char* string = calloc(strlen(type) + strlen(token->value) + strlen(template) + 1, sizeof(char));
	sprintf(string, template, type, token -> value);

	return string;
}
#ifndef TOKEN_H
#define TOKEN_H

#include "tokens.h"

typedef struct
{
	TOKENS *tokens;
	void *value;
} TOKEN;

const char semicolon_str = ";";
const char *return_str = "return";

void print_token_struct(TOKEN*);

#endif
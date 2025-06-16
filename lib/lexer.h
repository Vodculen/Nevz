#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "token.h"
#include "tokens.h"


typedef struct
{
	char *src;
	size_t src_size;
	char current;
	unsigned int index;
	unsigned int line;
} LEXER;

LEXER *clexer(char *src);

int eof(LEXER *lexer);
int is_integer_literal(char*);

void lexnewline(LEXER *lexer);
void lexfile(LEXER *lexer);

void* lex(char*);


#endif
#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "token.h"
#include "tokens.h"
#include "helpers.h"


typedef struct
{
	char* src;
	size_t src_size;
	char current;
	unsigned int index;
	unsigned int line;
} LEXER;

LEXER* new_lexer(char*);
TOKEN* numbers(LEXER*);
TOKEN* lex(LEXER*);
TOKEN* consume_type(LEXER*, int);

int check_symbol(char, char);
int eof(char);

char peek(LEXER*, int);

void consume(LEXER*);
void whitespace(LEXER*);


#endif
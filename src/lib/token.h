#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>
#include <stdio.h>
#include "tokens.h"
#include <string.h>

typedef struct
{
	char* value;
	TOKENS type;
} TOKEN;

TOKEN* new(char*, TOKENS);

const char* typestr(TOKENS);
char* tokenstr(TOKEN*);

#endif
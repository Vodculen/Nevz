#ifndef COMPILER_H
#define COMPILER_H

#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int compile(int argc, const char *argv[]);
char *fcompile(const char *filename);

#endif
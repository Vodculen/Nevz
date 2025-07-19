#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>


/**
 * @param filepath The path to the file or the file itself
 * @param buffer The contents of the file being written out
 * @param size The size of the buffer which is the same as the file
 * 
 * @returns If the file was successfully read into a buffer
 */
int readFile(const char* filepath, char** buffer, long* size);


#endif
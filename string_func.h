#ifndef STRING_FUNC_H
#define STRING_FUNC_H

#include <stdio.h>

void fGetLine(FILE* f, int max_len, char* str);

void Strcpy(char* str_to, const char* str_from);

int Find(int argc, const char* argv[], const char* str);

int Strcmp(const char* str1, const char* str2);

#endif // STRING_FUNC_H
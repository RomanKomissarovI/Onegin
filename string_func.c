#include "string_func.h"

void fGetLine(FILE* f, int max_len, char* str)
{
    int i = 0;
    int c = 0;
    while (i < max_len - 1 && (c = fgetc(f)) != '\n' && c != EOF)
    {
        str[i++] = (char) c;
    }

    if (c != '\n' && c != EOF)
        printf("fGetLine Error: too small maxlen of string\n");

    str[i] = '\0';
}

void Strcpy(char* str_to, char* str_from)
{
    while((*str_to++ = *str_from++) != '\0')
        ;
}
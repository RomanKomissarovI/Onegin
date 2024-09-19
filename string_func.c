#include <assert.h>

#include "string_func.h"
#include "color_print.h"

void fGetLine(FILE* f, int max_len, char* str)
{
    if (f == NULL)
        ColorPrint(RedColor, "Error file name\n");
    
    assert(f != NULL);
    
    int i = 0;
    int c = 0;
    
    while (i < max_len - 1 && (c = fgetc(f)) != '\n' && c != EOF)
    {
        str[i++] = (char) c;
    }

    if (c != '\n' && c != EOF)
        ColorPrint(RedColor, "fGetLine Error: too small maxlen of string\n");

    str[i] = '\0';
}

void Strcpy(char* str_to, const char* str_from)
{
    while((*str_to++ = *str_from++) != '\0')
        ;
}

int Strcmp(const char* str1, const char* str2)
{
    while((*str1 != '\0') && (*str1 == *str2))
    {
        ++str1;
        ++str2;
    }
    return *str1 - *str2;
}

int Find(int argc, const char* argv[], const char* str)
{
    for (int i = 1; i < argc - 1; ++i) {
        if (Strcmp(argv[i], str) == 0) {
            return i;
        }
    }
    return -1;
}
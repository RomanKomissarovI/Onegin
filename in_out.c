#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "in_out.h"

void ReadFileText(FILE* f, struct Text* text, const char* name_file) 
{
    assert(f != NULL);
    assert(text != NULL);

    struct stat st;

    if (stat(name_file, &st) == -1)
    {
        printf("Error file name\n");
        return;
    }

    int size = st.st_size;

    char* buffer = (char*) calloc(size, sizeof(char));
    int real_size = fread(buffer, sizeof(char), size, f);

    for (int i = 0; i < real_size; ++i) 
    {
        if (buffer[i] == '\r' || buffer[i] == '\n')
        {
            buffer[i] = '\0';
        }
    }

    text->len = size - real_size;
    text->text = (struct string*) calloc(text->len, sizeof(struct string));

    FillingText(text, buffer, real_size);

    free(buffer);
}

void FillingText(struct Text* text, char* buffer, int real_size)
{
    int end_str = 0;
    int num_str = 0;
    int begin_str = 0;
    while (end_str < real_size)
    {
        char is_empty = 1, ch = 0;
        while ((ch = buffer[end_str++]) != '\0')
        {
            if (ch != ' ' && ch != '\t') 
            {
                is_empty = 0;
            }
        }

        if (!is_empty) 
        {
            text->text[num_str].len = end_str - begin_str - 1;

            text->text[num_str].str = (char*) calloc(text->text[num_str].len, sizeof(char));
            strcpy(text->text[num_str].str, buffer + begin_str);
            ++num_str;
        }
        else
            text->len -= 1;

        begin_str = end_str;
    }
}

void WriteFileText(FILE* f, struct Text* text)
{
    int len = text->len;
    for (int i = 0; i < len; ++i)
    {
        fprintf(f, "%s\n", text->text[i].str);
    }
}
#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "in_out.h"

void ReadFileText(FILE* f, struct Text* text) 
{
    assert(f != NULL);
    assert(text != NULL);

    struct stat st;

    if (stat("input.txt", &st) == -1)
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

    int end_str = 0;
    int num_str = 0;
    int begin_str = 0;
    while (end_str < real_size)
    {
        while (buffer[end_str++] != '\0')
            ;
        
        if (end_str != begin_str) 
        {
            text->text[num_str].len = end_str - begin_str;

            text->text[num_str].str = (char*) calloc(text->text[num_str].len, sizeof(char));
            strcpy(text->text[num_str].str, buffer + begin_str);
                    //text->text[num_str].str = buffer + begin_str;
            ++num_str;
                    //printf("num_str now: %d ", num_str);
                    //printf("len_str now: %d   ", end_str - begin_str + 1);
                    //printf("begin: %d, end: %d\n", begin_str, end_str);
        }

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
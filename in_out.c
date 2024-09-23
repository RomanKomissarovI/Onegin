#include <assert.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "string_func.h"
#include "in_out.h"
#include "color_print.h"

#include "sort.h"
#include "compare.h"

static int ProcessStr(char* buffer, int real_size)
{
    int num_str = 0;
    for (int i = 0; i < real_size; ++i) 
    {
        if (buffer[i] == '\r' || buffer[i] == '\n')
        {
            buffer[i] = '\0';
            ++num_str;
        }
    }
    return num_str;
}

void ReadFileText(FILE* f, const char* name_file, struct Text* text) 
{
    if (f == NULL)
        ColorPrint(RedColor, "Error file name\n");

    assert(f != NULL);
    assert(text != NULL);

    struct stat st;

    if (stat(name_file, &st) == -1)
    {
        ColorPrint(RedColor, "Error file name\n");
        return;
    }

    int size = st.st_size;

    char* buffer = (char*) calloc(size + 1, sizeof(char));
    int real_size = fread(buffer, sizeof(char), size, f);

    int num_str = 0;

    num_str = ProcessStr(buffer, real_size);

    text->len = num_str;
    text->text_ptr = (struct String**) calloc(text->len, sizeof(struct String*));
    text->text = (struct String*) calloc(text->len, sizeof(struct String));

    FillText(text, buffer, real_size);

    free(buffer);
}

static void FreeErrText(struct Text* text, int num_str)
{
    for (int i = 0; i < num_str; ++i) 
    {
        free(text->text[i].str);
    }

    free(text->text);
    free(text->text_ptr);
    ColorPrint(RedColor, "Error: failed to allocate memory\n");
}

void FreeText(struct Text* text)
{
    int num_str = text->len;
    for (int i = 0; i < num_str; ++i) 
    {
        free(text->text[i].str);
    }

    free(text->text);
    free(text->text_ptr);
}

void FillText(struct Text* text, char* buffer, int real_size)
{
    int end_str = 0;
    int num_str = 0;
    int begin_str = 0;

    while (end_str < real_size)
    {
        char is_empty = 1, ch = 0;

        while ((ch = buffer[end_str++]) != '\0') // chech empty string (of 'spaces' and 'tabs')
        {
            if (ch != ' ' && ch != '\t') 
            {
                is_empty = 0;
            }
        }

        if (!is_empty) 
        {
            text->text[num_str].len = end_str - begin_str;
            text->text[num_str].str = (char*) calloc(text->text[num_str].len, sizeof(char));
            text->text_ptr[num_str] = &(text->text[num_str]);

            if (text->text[num_str].str == NULL) 
            {
                FreeErrText(text, num_str);
            }

            Strcpy(text->text[num_str].str, buffer + begin_str);

            ++num_str;
        }
        else
        {
            text->len -= 1;
        }

        begin_str = end_str;
    }
    realloc(text->text, text->len * sizeof(struct String));
}

void WriteFileText(FILE* f, struct Text* text)
{
    if (f == NULL)
        ColorPrint(RedColor, "Error file name\n");

    assert(f != NULL);
    assert(text != NULL);

    int len = text->len;
    for (int i = 0; i < len; ++i)
    {
        fprintf(f, "%s\n", text->text_ptr[i]->str);
    }    
}

void WriteFileAll(const char* name_input_file, const char* name_output_file, struct Text* text)
{
    FILE* input = fopen(name_input_file, "r");
    FILE* output = fopen(name_output_file, "w");

    assert(input != NULL);
    assert(output != NULL);

    ReadFileText(input, name_input_file, text);

    Qsort(text->text_ptr, sizeof(text->text_ptr[0]), 0, text->len, CompareStr);
    WriteFileText(output, text);

    fclose(output);
    output = fopen(name_output_file, "a");
    fprintf(output, "\n-----------------------------------------------------------------------------\n\n");

    Qsort(text->text_ptr, sizeof(text->text_ptr[0]), 0, text->len, CompareStrReverse);
    WriteFileText(output, text);
    fprintf(output, "\n-----------------------------------------------------------------------------\n\n");

    Qsort(text->text_ptr, sizeof(text->text_ptr[0]), 0, text->len, ComparePtr);
    WriteFileText(output, text);

    FreeText(text);
    fclose(input);
    fclose(output);
}
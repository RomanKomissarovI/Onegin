#include <stdio.h>
#include <string.h>

#include "sort.h"
#include "in_out.h"
#include "structs.h"

int main()
{
    struct Text text;
    text.text = NULL;
    text.len = 0;

    const char* name_file = "input.txt";
    FILE* f = fopen(name_file, "r");
    ReadFileText(f, &text, name_file);

    /*for(int i = 0; i < text.len; ++i)
    {
        printf("%s  %d\n", text.text[i].str, text.text[i].len);
    }
    printf("\n");*/

    sort(&text, 0, text.len);

    /*for(int i = 0; i < text.len; ++i)
    {
        printf("%s  %d\n", text.text[i].str, text.text[i].len);
    }*/

    FILE* write = fopen("output.txt", "w");

    WriteFileText(write, &text);

    fclose(f);
    fclose(write);

    return 0;
}
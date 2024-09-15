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

    const char* name_file = "Onegin.txt";
    /*printf("Enter file-input name: ");
    scanf("%s", name_file);
    for(int i = 0; i < 100; ++i)
    {
        if (name_file[i] == '\n')
        {
            name_file[i] = '\0';
            break;
        }
    }*/

    FILE* f = fopen(name_file, "r");
    ReadFileText(f, &text, name_file);

    sort(&text, 0, text.len, compare);

    FILE* write = fopen("output.txt", "w");

    WriteFileText(write, &text);

    fclose(f);
    fclose(write);

    return 0;
}
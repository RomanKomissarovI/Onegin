#include <stdlib.h>

#include "sort.h"
#include "in_out.h"
#include "structs.h"
#include "string_func.h"
#include "color_print.h"
#include "compare.h"

int main(int argc, const char* argv[])
{
    struct Text text = {NULL, 0};

    const char* input_file = "Onegin.txt";
    const char* output_file = "output.txt";
   
    typedef long long (*cmp)(void *a, void *b);
    cmp com = CompareStr;

    if (argc > 1){
        int ind = -1;

        if ((ind = Find(argc, argv, "-i")) > 0) {
            input_file = argv[ind + 1];
        }

        if ((ind = Find(argc, argv, "-o")) > 0) {
            output_file = argv[ind + 1];
        }

        if ((ind = Find(argc, argv, "-c")) > 0) {
            if (Strcmp(argv[ind + 1], "c") == 0)
            {
                com = CompareStr;
            }
            else
            {
                com = CompareStrReverse;
            }
        }

        if ((ind = Find(argc, argv, "-a")) > 0) {
            WriteFileAll(input_file, output_file, &text);
            return 0;
        }
    }
    else 
    {
        ColorPrint(GreenColor, "Enter file-input name: ");

        char name_file[256];
        fGetLine(stdin, 256, name_file);
        input_file = (const char*) name_file;
    }

    FILE* f = fopen(input_file, "r");
    ReadFileText(f, input_file, &text);

    Qsort(text.text, sizeof(text.text[0]), 0, text.len, com);

    FILE* write = fopen(output_file, "w");
    WriteFileText(write, &text);
    FreeText(&text);

    fclose(f);
    fclose(write);

    return 0;
}
#include "sort.h"
#include "in_out.h"
#include "structs.h"
#include "string_func.h"
#include "color_print.h"
#include "compare.h"

int main(int argc, const char* argv[])
{
    struct Text text = {NULL, 0};

    char input_file[256] = "Onegin.txt";
    char output_file[256] = "output.txt";

    switch (argc)
    {
    case 1:
        ColorPrint(GreenColor, "Enter file-input name: ");
        fGetLine(stdin, 256, input_file);
        break;
    case 2:
        Strcpy(input_file, argv[1]);
        break;
    case 3:
        Strcpy(input_file, argv[1]);
        Strcpy(output_file, argv[2]);
        break;
    default:
        ColorPrint(RedColor, "Too much arguments\n");
        break;
    }

    FILE* f = fopen(input_file, "r");
    ReadFileText(f, &text, input_file);

    Sort(text.text, sizeof(text.text[0]), 0, text.len, Compare);

    FILE* write = fopen(output_file, "w");
    WriteFileText(write, &text);

    fclose(f);
    fclose(write);

    return 0;
}
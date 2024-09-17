#include "sort.h"
#include "in_out.h"
#include "structs.h"
#include "string_func.h"
#include "color_print.h"

int main(int argc, const char* argv[])
{
    struct Text text = {NULL, 0};
    //text.text = NULL;
    //text.len = 0;

    char input_file[256];
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
    /*printf("Enter file-input name: ");
    scanf("%s", input_file);
    for(int i = 0; i < 100; ++i)
    {
        if (input_file[i] == '\n')
        {
            input_file[i] = '\0';
            break;
        }
    }*/

    FILE* f = fopen(input_file, "r");
    ReadFileText(f, &text, input_file);

    sort(&text, 0, text.len, compare);

    FILE* write = fopen(output_file, "w");
    WriteFileText(write, &text);

    fclose(f);
    fclose(write);

    return 0;
}
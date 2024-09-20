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

// very strange
    char input_file[256] = "Onegin.txt";
    char output_file[256] = "output.txt";

    /*char a[] = {'d', 'u', 's', 't', '\0'};
    char b[] = {'h', 'e', 'a', 'd', '\0'};

    struct String s1 = {a, sizeof(a)};
    struct String s2 = {b, sizeof(b)};
    printf("%d\n", '.');
    printf("%s %d %s %d\n", s1.str, s1.len, s2.str, s2.len);
    printf("%d", CompareVerse(&s1, &s2));

    return 0;*/

    /*int size = 0;
    scanf("%d", &size);
    int* a = (int*) calloc(size, sizeof(int));
    for(int i = 0; i < size; ++i){
        scanf("%d", &(a[i]));
    }
    for(int i = 0; i < size; ++i){
        printf("%d ", (a[i]));
    }
    printf("\n\n");
    //int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    typedef int (*cmp)(void *a, void *b);
    Qsort(a, sizeof(a[0]), 0, size, (cmp) CompareInt);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }
    free(a);*/

    //return 0;


   



    if (argc > 1){ // getopt
        int ind = -1;

        if ((ind = Find(argc, argv, "-i")) > 0) {
            Strcpy(input_file, argv[ind + 1]);
        }

        if ((ind = Find(argc, argv, "-o")) > 0) {
            Strcpy(output_file, argv[ind + 1]);
        }
    }
    else 
    {
        ColorPrint(GreenColor, "Enter file-input name: ");
        fGetLine(stdin, 256, input_file);
    }

    FILE* f = fopen(input_file, "r");
    ReadFileText(f, &text, input_file);

    Qsort(text.text, sizeof(text.text[0]), 0, text.len, CompareReverse);

    FILE* write = fopen(output_file, "w");
    WriteFileText(write, &text);

    fclose(f);
    fclose(write);

    return 0;
}
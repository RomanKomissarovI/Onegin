#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "sort.h"
#include "in_out.h"
#include "structs.h"

int main()
{
    //struct stat st;
    //printf("space and tab: %d %d")
    struct Text text;
    text.text = NULL;
    text.len = 0;
    FILE* f = fopen("input.txt", "r");

    ReadFileText(f, &text);

    for (int i = 0; i < text.len; ++i)
    {
        printf("%s\n", text.text[i].str);
    }

    //printf("\n\n text len: %d\n\n", text.len);

    sort(&text);
    for (int i = 0; i < text.len; ++i)
    {
        printf("%s\n", text.text[i].str);
    }

    FILE* write = fopen("output.txt", "w");

    WriteFileText(write, &text);

    fclose(f);
    fclose(write);
    
    //printf("%d", stat("input.txt", &st));

    /*int size = st.st_size;
    FILE* f = fopen("input.txt", "r");
    char* buffer = (char*) calloc(size, sizeof(char));
    int real_size = fread(buffer, sizeof(char), size, f);

    for (int i = 0; i < real_size; ++i) 
    {
        if (buffer[i] == '\r' || buffer[i] == '\n')
        {
            buffer[i] = '\0';
        }
    }

    text.len = size - real_size;
    text.text = (struct string*) calloc(text.len, sizeof(struct string));

    printf("size of file: %d\n", size);
    printf("real_size of file: %d\n", real_size);
    printf("text len: %d\n", text.len);

    for (int i = 0; i < real_size; ++i)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    int end_str = 0;
    int num_str = 0;
    int begin_str = 0;
    while (end_str < real_size)
    {
        while (buffer[end_str++] != '\0')
            ;
        
        if (end_str != begin_str) 
        {
            text.text[num_str].str = buffer + begin_str;
            text.text[num_str].len = end_str - begin_str;
            ++num_str;
            //printf("num_str now: %d ", num_str);
            printf("len_str now: %d   ", text.text[num_str - 1].len);
            //printf("begin: %d, end: %d\n", begin_str, end_str);
        }

        begin_str = end_str;
    }

    for (int i = 0; i < text.len; ++i)
    {
        printf("%s\n", text.text[i].str);
    }

    //printf("n_symb = %d\n read_symb = %d", size, w);

   //printf("%d\n", f);
    //fgets(q, 50, f);
    //printf("%s\n\n", q);
    //ReadFileText(f, &c);
    //printf("lwmefe");
    /*printf("len %d\n", c.len);
    for(int i = 0; i < c.len; ++i) {
        printf("%s", c.text[i].str);
    }*/
    //printf("%s", c.text[0].str);
    /*c[0] = "b";
    c[1] = "c";
    c[2] = "a";
    sort(c, 3);
    printf("%s %s %s", c[0], c[1], c[2]);*/

    //fclose(f);
    return 0;
}
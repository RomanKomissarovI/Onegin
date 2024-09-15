#include <assert.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "sort.h"
#include "structs.h"

void merge(struct Text* text, int l, int mid, int r);

/*void sort(struct Text* text)
{
    int len = text->len;

    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = 0; j < len - i - 1; ++j)
        {
            if (strcmp(text->text[j].str, text->text[j + 1].str) > 0)
            {
                char* a = text->text[j].str;

                text->text[j].str = text->text[j + 1].str;
                text->text[j + 1].str = a;
            }
        }
    }
}*/

void sort(struct Text* text, int l, int r) 
{
    assert(text != 0);
    if (r - l > 1) 
    {
        int mid = (r + l) / 2;
        sort(text, l, mid);
        sort(text, mid, r);
        merge(text, l, mid, r);
    }
}
void merge(struct Text* text, int l, int mid, int r)
{
    struct string* arr = (struct string*) calloc(r - l, sizeof(struct string));
    int l_ptr = l;
    int r_ptr = mid;
    int arr_ptr = 0;

    while ((l_ptr < mid) && (r_ptr < r))
    {
        struct string l_string  = text->text[l_ptr];
        struct string r_string  = text->text[r_ptr];
        if (strcmp(l_string.str, r_string.str) > 0)
        {
            arr[arr_ptr++] = r_string;
            ++r_ptr;
        }
        else
        {
            arr[arr_ptr++] = l_string;
            ++l_ptr;
        }
    }

    while (l_ptr < mid)
    {
        arr[arr_ptr++] = text->text[l_ptr++];
    }

    while (r_ptr < r)
    {
        arr[arr_ptr++] = text->text[r_ptr++];
    }

    for (int i = l; i < r; ++i)
    {
        text->text[i] = arr[i - l];
    }

    free(arr);
}
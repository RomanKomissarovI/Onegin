#include <assert.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "sort.h"
#include "structs.h"

void merge(struct Text* text, int l, int mid, int r, int (*compare) (struct string s1, struct string s2));

void sort(struct Text* text, int l, int r, int (*compare) (struct string s1, struct string s2)) 
{
    assert(text != NULL);

    if (r - l > 1) 
    {
        int mid = (r + l) / 2;

        sort(text, l, mid, compare);
        sort(text, mid, r, compare);

        merge(text, l, mid, r, compare);
    }
}
void merge(struct Text* text, int l, int mid, int r, int (*compare) (struct string s1, struct string s2))
{
    struct string* arr = (struct string*) calloc(r - l, sizeof(struct string));

    int l_ptr = l;
    int r_ptr = mid;
    int arr_ptr = 0;

    while ((l_ptr < mid) && (r_ptr < r))
    {
        struct string l_string  = text->text[l_ptr];
        struct string r_string  = text->text[r_ptr];

        if (compare(l_string, r_string) > 0)
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

int compare(struct string s1, struct string s2)
{
    char* s1_ptr = s1.str;
    char* s2_ptr = s2.str;
    
    while (*s1_ptr != '\0')
    {
        if (*s2_ptr != '\0' && !isalnum(*s1_ptr))
        {
            ++s1_ptr;
            continue;
        }
        if (*s2_ptr != '\0' && !isalnum(*s2_ptr))
        {
            ++s2_ptr;
            continue;
        }
        if (*s1_ptr != *s2_ptr)
        {
            break;
        }
        ++s1_ptr;
        ++s2_ptr;
    }
    return *s1_ptr - *s2_ptr;
}
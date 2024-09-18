#include <assert.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include "sort.h"
#include "structs.h"

void merge(void* text, size_t size_el, int l, int mid, int r, int (*compare) (void* s1, void* s2));

void copy(void* to, void* from, size_t size_el);

void sort(void* text, size_t size_el, int l, int r, int (*compare) (void* s1, void* s2)) 
{
    assert(text != NULL);

    if (r - l > 1) 
    {
        int mid = (r + l) / 2;

        sort(text, size_el, l, mid, compare);
        sort(text, size_el, mid, r, compare);

        merge(text, size_el, l, mid, r, compare);
    }
}
void merge(void* text, size_t size_el, int l, int mid, int r, int (*compare) (void* s1, void* s2))
{
    void* arr = (void*) calloc(r - l, size_el);

    int l_ptr = l;
    int r_ptr = mid;
    int arr_ptr = 0;

    //printf("aa\n");

    while ((l_ptr < mid) && (r_ptr < r))
    {
        char* l_string  = (char*) text + l_ptr * size_el;
        char* r_string  = (char*) text + r_ptr * size_el;

        if (compare(l_string, r_string) > 0)
        {
            copy((char*) arr + size_el * arr_ptr++, r_string, size_el);
            ++r_ptr;
        }
        else
        {
            copy((char*) arr + size_el * arr_ptr++, l_string, size_el);
            ++l_ptr;
        }
    }

    while (l_ptr < mid)
    {
        copy((char*) arr + size_el * arr_ptr++, (char*) text + size_el * l_ptr++, size_el);
    }

    while (r_ptr < r)
    {
        copy((char*) arr + size_el * arr_ptr++, (char*) text + size_el * r_ptr++, size_el);
    }

    for (int i = l; i < r; ++i)
    {
        copy((char*) text + size_el * i, (char*) arr + size_el * (i - l), size_el);
    }

    //printf("bb\n");

    free(arr);
}

int compare(void* s1, void* s2)
{
    struct string* s1_real = (struct string*) s1;
    struct string* s2_real = (struct string*) s2;
    char* s1_ptr = s1_real->str;
    char* s2_ptr = s2_real->str;

    assert(s2_ptr != NULL);
    assert(s1_ptr != NULL);
    
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

void copy(void* to, void* from, size_t size_el)
{
    char* c_to = (char*) to;
    char* c_from = (char*) from;

    while (size_el >= 8) 
    {
        *(long long*) c_to = *(long long*) c_from;
        size_el -= 8;
        c_to += 8;
        c_from += 8;
    }

    while (size_el >= 4)
    {
        *(int*) c_to = *(int*) c_from;
        size_el -= 4;
        c_to += 4;
        c_from += 4;
    }

    while (size_el >= 1)
    {
        *(char*) c_to = *(char*) c_from;
        size_el -= 1;
        c_to += 1;
        c_from += 1;
    }
}
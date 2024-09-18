#include <assert.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include "sort.h"
#include "structs.h"
#include "compare.h"

void Merge(void* text, size_t size_el, int l, int mid, int r, int (*compare) (void* s1, void* s2));

void Sort(void* text, size_t size_el, int l, int r, int (*compare) (void* s1, void* s2)) 
{
    assert(text != NULL);

    if (r - l > 1) 
    {
        int mid = (r + l) / 2;

        Sort(text, size_el, l, mid, compare);
        Sort(text, size_el, mid, r, compare);

        Merge(text, size_el, l, mid, r, compare);
    }
}
void Merge(void* text, size_t size_el, int l, int mid, int r, int (*compare) (void* s1, void* s2))
{
    void* arr = (void*) calloc(r - l, size_el);

    int l_ptr = l;
    int r_ptr = mid;
    int arr_ptr = 0;

    while ((l_ptr < mid) && (r_ptr < r))
    {
        char* l_string  = (char*) text + l_ptr * size_el;
        char* r_string  = (char*) text + r_ptr * size_el;

        if (compare(l_string, r_string) > 0)
        {
            Copy((char*) arr + size_el * arr_ptr++, r_string, size_el);
            ++r_ptr;
        }
        else
        {
            Copy((char*) arr + size_el * arr_ptr++, l_string, size_el);
            ++l_ptr;
        }
    }

    while (l_ptr < mid)
    {
        Copy((char*) arr + size_el * arr_ptr++, (char*) text + size_el * l_ptr++, size_el);
    }

    while (r_ptr < r)
    {
        Copy((char*) arr + size_el * arr_ptr++, (char*) text + size_el * r_ptr++, size_el);
    }

    for (int i = l; i < r; ++i)
    {
        Copy((char*) text + size_el * i, (char*) arr + size_el * (i - l), size_el);
    }

    free(arr);
}

void Copy(void* to, void* from, size_t size_el)
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
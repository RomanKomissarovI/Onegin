#include <assert.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#include "sort.h"
#include "structs.h"

void Qsort(void* a, size_t size_el, int l, int r, long long (*comp_func)(void *a, void *b))
{
    if (r - l <= 1)
    {
        return;
    }

    void* pivot = (char*) a + ((l + r) / 2) * size_el;
    int l_ptr = l;
    int r_ptr = r - 1;

    while (r_ptr >= l_ptr)
    {
        while (comp_func((char*) a + r_ptr * size_el, pivot) > 0)
            --r_ptr;
        while (comp_func((char*) a + l_ptr * size_el, pivot) < 0)
            ++l_ptr;
        
        if (l_ptr <= r_ptr)
        {
            if (pivot == (char*) a + l_ptr * size_el)
            {
                pivot = (char*) a + r_ptr * size_el;
            }
            else if (pivot == (char*) a + r_ptr * size_el)
            {
                pivot = (char*) a + l_ptr * size_el;
            }
            Swap((char*) a + l_ptr++ * size_el, (char*) a + r_ptr-- * size_el, sizeof(int));
        }
    }
    int g = (l_ptr - r_ptr == 1) ? l_ptr : l_ptr - 1;
    Qsort(a, size_el, l, g, comp_func);
    Qsort(a, size_el, g, r, comp_func);
}

void Swap(void* to, void* from, size_t size_el)
{
    char* c_to = (char*) to;
    char* c_from = (char*) from;

    while (size_el >= 8) 
    {
        long long tr = *(long long*) c_to;
        *(long long*) c_to = *(long long*) c_from;
        *(long long*) c_from = tr;
        size_el -= 8;
        c_to += 8;
        c_from += 8;
    }

    while (size_el >= 4)
    {
        int tr = *(int*) c_to;
        if (c_from == c_to){
        }
        *(int*) c_to = *(int*) c_from;
        *(int*) c_from = tr;

        size_el -= 4;
        c_to += 4;
        c_from += 4;
    }
    
    while (size_el >= 1)
    {
        char tr = *(char*) c_to;
        *(char*) c_to = *(char*) c_from;
        *(char*) c_from = tr;
        size_el -= 1;
        c_to += 1;
        c_from += 1;
    }

}
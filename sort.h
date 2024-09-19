#ifndef SORT_H
#define SORT_H

#include "structs.h"
#include <stdio.h>

//void Sort(void* text, size_t size_el, int l, int r, int (*compare) (void* s1, void* s2));

//void Copy(void* to, void* from, size_t size_el);

//void Qsort(void *a, size_t size_el, int l, int r, int (*comp_func)(void *a, void *b));

void Qsort(void* a, size_t size_el, int l, int r, int (*comp_func)(void *a, void *b));

void Swap(void* to, void* from, size_t size_el);

int Min(int a, int b);

#endif //SORT_H
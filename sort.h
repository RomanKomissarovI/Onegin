#ifndef SORT_H
#define SORT_H

#include "structs.h"
#include <stdio.h>

void Qsort(void* a, size_t size_el, int r, long long (*comp_func)(void *a, void *b));

void Swap(void* to, void* from, size_t size_el);

int Min(int a, int b);

#endif //SORT_H
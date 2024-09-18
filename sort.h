#ifndef SORT_H
#define SORT_H

#include "structs.h"
#include <stdio.h>

void sort(void* text, size_t size_el, int l, int r, int (*compare) (void* s1, void* s2));

int compare(void* s1, void* s2);

#endif //SORT_H
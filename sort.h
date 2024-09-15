#ifndef SORT_H
#define SORT_H

#include "structs.h"

void sort(struct Text* text, int l, int r, int (*compare) (struct string s1, struct string s2));

int compare(struct string s1, struct string s2);

#endif //SORT_H
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

#include "structs.h"
#include "compare.h"

int Compare(void* s1, void* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    struct String* s1_real = (struct String*) s1;
    struct String* s2_real = (struct String*) s2;

    char* s1_ptr = s1_real->str;
    char* s2_ptr = s2_real->str;

    //printf("compare: %p %s 1\n", s1, s1_ptr);
    //printf("compare: %p %s 1\n", s2, s2_ptr);
    
    while (*s1_ptr != '\0')
    {
        while ((*s1_ptr != '\0') && (!isalnum(*s1_ptr)))
        {
            ++s1_ptr;
        }
        while ((*s2_ptr != '\0') && (!isalnum(*s2_ptr)))
        {
            ++s2_ptr;
        }
        if (ToUpper(*s1_ptr) != ToUpper(*s2_ptr))
        {
            return ToUpper(*s1_ptr) - ToUpper(*s2_ptr);
        }
        if (*s1_ptr != '\0')
        {
            ++s1_ptr;
        }
        if (*s2_ptr != '\0')
        {
            ++s2_ptr;
        }
    }
    while ((*s2_ptr != '\0') && (!isalnum(*s2_ptr)))
    {
        ++s2_ptr;
    }

    return ToUpper(*s1_ptr) - ToUpper(*s2_ptr);
}

int CompareVerse(void* s1, void* s2)
{
    return -Compare(s1, s2);
}

int CompareInt(int *a, int *b)
{
    return *a - *b;
}

int ToUpper(int c)
{
    return (!(97 <= c && c <= 122)) ? c : c - 32;
}
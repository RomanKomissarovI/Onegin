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

int CompareReverse(void* s1, void* s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    struct String* s1_real = (struct String*) s1;
    struct String* s2_real = (struct String*) s2;

    char* s1_stop = s1_real->str;
    char* s2_stop = s2_real->str;

    char* end = s1_stop;
    while (*end != '\0') 
    {
        ++end;
    }
    char* s1_ptr = end;

    end = s2_stop;
    while (*end != '\0') 
    {
        ++end;
    }
    char* s2_ptr = end;

    while ((s1_ptr >= s1_stop) && (s2_ptr >= s2_stop))
    {
        while ((s1_ptr > s1_stop) && (!isalnum(*s1_ptr)))
        {
            --s1_ptr;
        }

        while ((s2_ptr > s2_stop) && (!isalnum(*s2_ptr)))
        {
            --s2_ptr;
        }

        if ((ToUpper(*s1_ptr) != ToUpper(*s2_ptr)) || ((s1_ptr == s1_stop) || (s2_ptr == s2_stop)))
        {
            return ToUpper(*s1_ptr) - ToUpper(*s2_ptr);
        }

        --s1_ptr;
        --s2_ptr;
    }
    //printf("\n%d assert: %s: %d, \n%s: %d\n%d\n\n", s2_ptr < s2_stop, s1_real->str, *s1_ptr, s2_real->str, *s2_ptr, ToUpper(*s1_ptr) - ToUpper(*s2_ptr));
    assert(0 != 0);
}

int CompareInt(int *a, int *b)
{
    return *a - *b;
}

int ToUpper(int c)
{              
    return ((!(97 <= c && c <= 122)) ? c : c - 32) * (isalnum(c) ? 1 : 0);
}
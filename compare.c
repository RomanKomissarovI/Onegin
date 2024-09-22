#include <assert.h>
#include <ctype.h>
#include <stdio.h>

#include "structs.h"
#include "compare.h"

static const int ASCII_A = 97;
static const int ASCII_Z = 122;


long long CompareStr(void* s1, void* s2)
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

long long CompareStrReverse(void* s1, void* s2)
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
}

long long ComparePtr(void* ptr1, void* ptr2)
{
    return (long long) ptr1 - (long long) ptr2;
}

long long ToUpper(int c)
{              
    return ((!(ASCII_A <= c && c <= ASCII_Z)) ? c : c - 32) * (isalnum(c) ? 1 : 0); // 0, если не буква или цифра, Upper иначе
}
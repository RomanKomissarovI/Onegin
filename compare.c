#include <assert.h>
#include <ctype.h>

#include "structs.h"
#include "compare.h"

int Compare(void* s1, void* s2)
{
    struct String* s1_real = (struct String*) s1;
    struct String* s2_real = (struct String*) s2;
    char* s1_ptr = s1_real->str;
    char* s2_ptr = s2_real->str;
    
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

int CompareVerse(void* s1, void* s2)
{
    return -Compare(s1, s2);
}
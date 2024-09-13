#include <assert.h>
#include <string.h>


#include "sort.h"

void sort(struct Text* text)
{
    int len = text->len;

    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = 0; j < len - i - 1; ++j)
        {
            if (strcmp(text->text[j].str, text->text[j + 1].str) > 0)
            {
                char* a = text->text[j].str;
                
                text->text[j].str = text->text[j + 1].str;
                text->text[j + 1].str = a;
            }
        }
    }
}

/*void sort(sort_type arr[], int len) 
{
    assert(sizeof(arr) > 0);

    if (len > 1) 
    {
        int mid = len / 2;
        sort(&arr[0], mid + 1);
        sort(&arr[mid + 1], len - mid - 1);
        return merge(mid + 1, len - mid - 1);
    }
}

sort_type[] merge(sort_type arr1[], int len1, sort_type arr2[], int len2)
{

}*/

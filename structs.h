#ifndef STRUCTS_H
#define STRUCTS_H

struct string
{
    char* str;
    int len;
};


struct Text
{
    struct string* text;
    int len;
};

#endif // STRUCTS_H
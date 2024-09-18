#ifndef STRUCTS_H
#define STRUCTS_H

struct String
{
    char* str;
    int len;
};


struct Text
{
    struct String* text;
    int len;
};

#endif // STRUCTS_H
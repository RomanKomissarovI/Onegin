#ifndef STRUCTS_H
#define STRUCTS_H

struct String
{
    char* str;
    int len;
};


struct Text
{
    struct String** text_ptr;
    struct String* text;
    int len;
};

#endif // STRUCTS_H
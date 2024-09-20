#ifndef IN_OUT_H
#define IN_OUT_H

#include "structs.h"
#include <stdio.h>

void FillText(struct Text* text, char* buffer, int real_size);

void ReadFileText(FILE* f, struct Text* text, const char* name_file);

void WriteFileText(FILE* f, struct Text* text);

#endif //IN_OUT_H
#ifndef IN_OUT_H
#define IN_OUT_H

#include "structs.h"
#include <stdio.h>

void FillText(struct Text* text, char* buffer, int real_size);

void ReadFileText(FILE* f, const char* name_file, struct Text* text);

void WriteFileText(FILE* f, struct Text* text);

void WriteFileAll(const char* name_input_file, const char* name_output_file, struct Text* text);

void FreeText(struct Text* text);

#endif //IN_OUT_H
#ifndef IN_OUT_H
#define IN_OUT_H

#include "structs.h"
#include <stdio.h>

void ReadFileText(FILE* f, struct Text* text); 

void WriteFileText(FILE* f, struct Text* text);

#endif //IN_OUT_H
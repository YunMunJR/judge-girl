#include "doll.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
Doll* newDoll(char top, char bottom) {
    Doll* doll = (Doll*)malloc(sizeof(Doll));
    doll->top = top; doll->bottom = bottom; doll->interior = NULL;
    return doll;
}
void package(Doll* outer, Doll* inter) {
    outer->interior = inter;
}
const char* doll_c_str(Doll* doll) {
    if (doll == NULL)return NULL;

    char* s = malloc(100000);
    s[0] = doll->top;
    if (doll_c_str(doll->interior))strcat(s, doll_c_str(doll->interior));

    int m = strlen(s);
    s[m] = doll->bottom;
    s[m + 1] = '\0';
    return s;
}
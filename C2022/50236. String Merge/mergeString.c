#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "mergeString.h"
void mergeString(char** P, char L[26], char* A) {
    int map[26] = { 0 }, min, idx, n = 0, num, Alength = 0, totallen = 0;
    for (int i = 0; i < 26; i++){
        map[(int)(L[i] - 'a')] = i;
    }
    min = *P[0];
    while (P[n]) {
        n++;
    }
    int* count = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        count[i] = 0;
    }
    for (int i = 0; i < n; i++){
        totallen += strlen(P[i]);
    }
    while (Alength < totallen) {
        min = 127; idx = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] < strlen(P[i])) {
                num = map[(int)(*(P[i] + count[i]) - 'a')];
                if (min > num) { 
                    min = num; 
                    idx = i;
                }
            }
        }
        A[Alength] = L[min]; 
        count[idx]++; 
        Alength++;
    }
    free(count);
}
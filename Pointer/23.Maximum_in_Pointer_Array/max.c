#include "max.h"
int max(int *iptr[], int n){
    int i,j;
    int max; max=*iptr[0];
    for(i=0;i<n;i++){
        if(max<*iptr[i]){
            max=*iptr[i];
        }
    }
    return max;
};
#include "max.h"
int max(int array[5][5]) {
    int k=array[0][0],i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(k<array[i][j]){
                k=array[i][j];
            }
        }
    }
    return k;
}
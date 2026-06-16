#include"posneg.h"
void posneg(int array[5][5], int result[2]){
    int i,j,r1=0,r2=0;
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            if(array[i][j]>0){
                r2++;
            }else if(array[i][j]==0){
                continue;
            }else{
                r1++;
            }
        }
    }
    result[0]=r1;
    result[1]=r2;
}
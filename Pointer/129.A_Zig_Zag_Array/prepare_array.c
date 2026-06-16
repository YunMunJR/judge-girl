#include "prepare_array.h"
void prepare_array(int buffer[], int* array[], int row, int column[]){
    int n = 0,col;
    for (int i = 0; i < row; i++){
        col = column[i];
        array[i] = &buffer[n];
        n += col;
    }
}
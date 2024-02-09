#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define ARRAYSIZE 65536
int power(int base, int exp) {
    int re = 1;
    for (int i = 0; i < exp; i++){
        re *= base;
    }
    return re;
}
int main(){
    char filename[201]; short num = 0; int n = 0, c, count = 0, maxidx = 0;
    static short arr[ARRAYSIZE];
    memset(arr, 0, ARRAYSIZE);
    scanf("%s", filename);
    FILE* fp;
    fp = fopen(filename, "rb"); 
    for (int i = 0; i < 4; i++){
        c = fgetc(fp);
        n += c * power(256, i);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            c = fgetc(fp);
            num += c * power(256, j);
        }
        arr[num + 32768] += 1;num = 0;
    }
    for (int i = 0; i < ARRAYSIZE; i++){
        if (arr[i] >= arr[maxidx]){
            maxidx = i;
        }
    }
    printf("%d\n", maxidx - 32768);
    printf("%d", arr[maxidx]);
    fclose(fp);
    return 0;
}
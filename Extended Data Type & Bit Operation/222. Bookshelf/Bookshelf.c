#include <stdio.h>
#include <stdint.h>
int hasEOF = 0;
int readchar() {
    static int N = 1 << 20;
    static char buf[1 << 20];
    static char* p = buf, * end = buf;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int* x) {
    char c, neg;
    while ((c = readchar()) < '-') { if (c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c - '0' : 0;
    while ((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c - '0';
    *x *= neg;
    return 1;
}
int main() {
    uint64_t seq = 1; int32_t x,number[256] = { 0 }, max = 0, ans[8] = { 0 };
    while (ReadInt(&x)) {
        number[x] = seq; 
        seq++;
    }
    for (int i = 7; i >= 0; i--){
        for (int j = 1; j < 256; j++){
            if (max < number[j]){
                max = number[j]; 
                ans[i] = j;
            }
        }
        number[ans[i]] = 0; 
        max = 0;
    }
    for (int i = 0; i < 8; i++){
        printf("%d ", ans[i]);
    }
    return 0;
}
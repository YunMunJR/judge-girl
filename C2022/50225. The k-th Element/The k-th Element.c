#include <stdio.h>
#define row 1
#define column 0
typedef struct n {
    int r, c;
}n_;
int Is_Row_Or_Column(int M1, int N1,int k1) {
    int sum = 0, n = (N1 > M1) ? M1 : N1;
    int b;
    b = 0;
    for (int i = 0; i < n; i++){
        if (k1 > sum && k1 <= sum+N1 - i){
            b = 1;
        }   
        sum += (N1 + M1 - 2 * i - 1);
    }
    return b;
}
int row_r(int M1, int N1, int k1) {
    int sum = 0, n = (N1 > M1) ? M1 : N1;
    n_ valu={0,0};
    for (int i = 0; i < n; i++){
        if (k1 > sum && k1 <= sum + N1 - i){
            valu.r = k1 - sum + i;
            break;
        }
        sum += (N1 + M1 - 2 * i - 1);
    }
    return valu.r;
}int row_c(int M1, int N1, int k1) {
    int sum = 0, n = (N1 > M1) ? M1 : N1;
    n_ valu={0,0};
    for (int i = 0; i < n; i++){
        if (k1 > sum && k1 <= sum + N1 - i){
            valu.c = i;
            break;
        }
        sum += (N1 + M1 - 2 * i - 1);
    }
    return valu.c+1;
}
int column_r(int M1, int N1, int k1) {
    int sum = N1, n = (N1 > M1) ? M1 : N1;
    n_ valu = { 0,0 };
    for (int i = 0; i < n; i++){
        if (k1 > sum && k1 <= sum + M1 - 1){
            valu.r = i;
            break;
        }
        sum += (N1 + M1 - 2 * i - 3);
    }
    return valu.r+1;
}
int column_c(int M1, int N1, int k1) {
    int sum = N1, n = (N1 > M1) ? M1 : N1;
    n_ valu = { 0,0 };
    for (int i = 0; i < n; i++){
        if (k1 > sum && k1 <= sum + M1 - 1){
            valu.c = k1-sum+i+1;
            break;
        }
        sum += (N1 + M1 - 2 * i - 2);
    }
    return valu.c;
}
int main(){
    int M, N, k;
    scanf("%d%d%d", &M, &N, &k);
    int val = Is_Row_Or_Column(M, N, k);
    if (val == row){
        printf("%d %d", row_c(M, N, k), row_r(M, N, k));
    }else{
        printf("%d %d", column_c(M, N, k), column_r(M, N, k));
    }
    return 0;
}
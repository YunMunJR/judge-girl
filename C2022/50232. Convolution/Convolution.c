 // Convolution.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#define MAXn 512
#include <stdio.h>
void scan_array(int arr[][512], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}
int convolution(int narr[][512], int karr[][512],int i,int j,int k) {
    int ans = 0;
    for (int ii = i; ii < (i + k); ii++) {
        for (int jj = j; jj < (j + k); jj++) { 
            ans += (narr[ii][jj] * karr[ii - i][jj - j]);  
        }
    }
    return ans;
}
int main(){
    static int narr[MAXn][MAXn], karr[MAXn][MAXn]; 
    int n, k;
    scanf("%d%d", &n, &k);
    scan_array(narr, n);
    scan_array(karr, k);
    for (int i = 0; i < (n - k + 1); i++) {
        for (int j = 0; j < (n - k + 1); j++){
            printf("%d ", convolution(narr, karr, i, j, k));
        }
        putchar('\n');
    }
    return 0;
}
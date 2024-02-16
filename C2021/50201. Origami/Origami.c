#define maxr 600
#define maxc 600
#include <stdio.h>
int main(){
    int r, c, operation, k, i1, j1; static int board[maxr][maxc] = { 0 };
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++){
            scanf("%d", &board[i][j]);
        }
    }
    i1 = 0; j1 = c;
    while (scanf("%d%d", &operation, &k) != EOF) {
        if (operation == 1) {
            for (int i = i1; i < i1 + k; i++) {
                for (int j = 0; j < j1; j++) {
                    board[2 * (i1 + k) -1 - i][j] += board[i][j]; 
                    board[i][j] = 0;
                }
            }
            i1 += k;
        }else if (operation == 2){
            for (int i = i1; i < r; i++) {
                for (int j = j1 - 2 * k; j < j1 - k; j++) {
                    board[i][j] += board[i][2 * (j1 - k) - j - 1]; 
                    board[i][2 * (j1 - k) - j - 1] = 0;
                }
            }
            j1 -= k;
        }else{
            for (int i = i1; i < i1 + k; i++) {
                for (int j = j1 - k; j < j1; j++) {
                    if (j - i > j1 - k - i1){
                        board[i1 + j - j1 + k][j1 - k + i - i1] += board[i][j]; 
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
    for (int i = i1; i < r; i++) {
        for (int j = 0; j < j1; j++){
            printf("%d ", board[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
#define MAXN 500
#include <stdio.h>
int main(){
    static int board[MAXN + 2][MAXN + 3] = { 0 }, r, c;
    scanf("%d%d", &r, &c);
    for (int i = 2; i < r + 2; i++) {
        for (int j = 2; j < c + 2; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j - 1] == board[i][j] && board[i][j - 2] == board[i][j]) {
                board[i][j - 1] = 0; 
                board[i][j] = 0; 
                board[i][j - 2] = 0;
            }else if (board[i - 1][j] == board[i][j] && board[i - 2][j] == board[i][j]) {
                board[i - 1][j] = 0; 
                board[i][j] = 0; 
                board[i - 2][j] = 0;
            }else if (board[i - 1][j - 1] == board[i][j] && board[i - 1][j] == board[i][j]) {
                board[i - 1][j - 1] = 0; 
                board[i][j] = 0; 
                board[i - 1][j] = 0;
            }else if (board[i - 1][j - 1] == board[i][j] && board[i][j - 1] == board[i][j]) {
                board[i - 1][j - 1] = 0; 
                board[i][j] = 0; 
                board[i][j - 1] = 0;
            }else if (board[i - 1][j] == board[i][j] && board[i - 1][j + 1] == board[i][j]) {
                board[i - 1][j] = 0; 
                board[i][j] = 0; 
                board[i - 1][j + 1] = 0;
            }else if (board[i][j - 1] == board[i][j] && board[i - 1][j] == board[i][j]) {
                board[i][j - 1] = 0; 
                board[i][j] = 0; 
                board[i - 1][j] = 0;
            }
        }
    }
    for (int i = 2; i < r + 2; i++) {
        for (int j = 2; j < c + 2; j++){
            printf("%d ", board[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
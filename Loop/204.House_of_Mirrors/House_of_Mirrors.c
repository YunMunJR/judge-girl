#include <stdio.h>
#define up 0
#define down 1
#define left 2
#define right 3
int solve(int arr[102][102], int n1, int W1, int D1) {
    int i, j,dir;    
    int k;
    if (n1 >= 0 && n1 < W1){
        j = n1 + 1; i = D1;
        dir = up;
        while (j < W1 + 1 && i>0){
            k = (arr[i][j] == 0);
            if (dir == up && k){
                i--;
            }else{
                if (k || dir == up){
                    dir = right;
                    j++;
                }else{
                    dir = up;
                    i--;
                }
            }
        }
    }else if (n1 >= W1 && n1 < W1 + D1){
        i = W1 + D1 - n1; j = W1;
        dir = left;
        while (i < D1 + 1 && j>0){
            k = (arr[i][j] == 0);
            if (dir == left && k){
                j--;
            }else{
                if (k || dir == left){
                    dir = down;
                    i++;
                }else{
                    dir = left;
                    j--;
                }
            }
        }
    }else if (n1 >= W1 + D1 && n1 < 2 * W1 + D1){
        i = 1; j = 2 * W1 + D1 - n1;
        dir = down;
        while (i < D1 + 1 && j>0){
            k = (arr[i][j] == 0);
            if (dir == down && k){
                i++;
            }else{
                if (k || dir == down){
                    dir = left;
                    j--;
                }else{
                    dir = down;
                    i++;
                }
            }
        }
    }else{
        i = n1 -( 2 * W1 + D1) + 1; j = 1;
        dir = right;
        while (i >0 && j<W1+1){
            k = (arr[i][j] == 0);
            if (dir == right && k){
                j++;
            }else{
                if (k || dir == right){
                    dir = up;
                    i--;
                }else{
                    dir = right;
                    j++;
                }
            }
        }
    }
    int ans = arr[i][j];
    return ans;
}
int main(){
    int W, D;
    scanf("%d%d", &W, &D);
    int a[102][102] = { 0 };
    for (int i = 1; i < D+1; i++){
        for (int j = 1; j < W+1; j++){
            scanf("%d", &a[i][j]);
        }   
    }
    for (int i = 1; i < W+ 1; i++){
        a[D + 1][i] = i - 1;
        a[0][i] = 2*W+D-i;
    }
    for (int i = 1; i < D + 1; i++){
        a[i][0] = 2 * W + D+i - 1;
        a[i][W + 1] = W + D - i;
    }
    for (int i = 0; i <2*(W+D); i++){
        printf("%d", solve(a, i, W, D));
        (i!= 2 * (W + D)-1)&&putchar('\n');
    }
    return 0;
}
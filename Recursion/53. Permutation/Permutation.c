#include <stdio.h>
void perm(int* num, int i,int N) {
    int j, k, tmp;
    if (i < N) {
        for (j = i; j <= N; j++) {
            tmp = num[j];
            for (k = j; k > i; k--){
                 num[k] = num[k - 1];
            }   
            num[i] = tmp;
            perm(num, i + 1,N);
            for (k = i; k < j; k++){
                num[k] = num[k + 1];
            }       
            num[j] = tmp;
        }
    }
    else {  
        for (j = 1; j <= N; j++){
            printf("%d ", num[j]);
        }       
        putchar('\n');
    }
}
int main(void) {
    int num[10]={0}, i,N;
    scanf("%d", &N);
    for (i = 1; i <= N; i++){
        scanf("%d",&num[i]);
    }     
    for (int i = N; i >=1; i--){
        for (int j = 1; j < i; j++){
            if (num[j] > num[j + 1]){
                int temp = num[j + 1]; 
                num[j + 1] = num[j]; 
                num[j] = temp;
            }
        }
    } 
    perm(num, 1,N);
    return 0;
}
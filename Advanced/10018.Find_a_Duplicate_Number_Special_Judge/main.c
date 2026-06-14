#include <stdio.h>
#define MAXN 100000
int main(){
    int a[MAXN], N, var;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &var);
        a[var]++;
        if(a[var] >= 2){
            printf("%d\n", var);
            return 0;
        }
    }

    return 0;
}
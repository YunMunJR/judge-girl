#include <stdio.h>
int main(){
    static int hash[100000][10]={{0,0,0,0,0,0,0,0,0,0}}; 
    int S, C, K, exsit;
    scanf("%d%d", &S, &C);
    while (scanf("%d", &K) != EOF) {
        exsit = 0;
        for (int i = 0; i < C; i++) {
            if (hash[(77 * K + 2222) % S][i] == K) {
                exsit = 1; 
                hash[(77 * K + 2222) % S][i] = 0; 
                printf("%d %d\n", K, (77 * K + 2222) % S); 
                break; 
            }
        }
        if (!exsit) {
            for (int i = 0; i < C; i++) { 
                if (hash[(77 * K + 2222) % S][i] == 0){ 
                    hash[(77 * K + 2222) % S][i] = K; 
                    break; 
                } 
            }
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
typedef struct data {
    long long X, Y, E, N, F;
}robots;
int main(){
    long long M, N,explode=0,time=0,i;
    robots R1, R2;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &M, &N, &R1.X, &R1.Y, &R1.E, &R1.N, &R1.F, &R2.X, &R2.Y, &R2.E, &R2.N, &R2.F);
    for(i=1;i<=10000;i++){
        if (R1.F > 0){
            if (i % (R1.E + R1.N) <= R1.N&& i % (R1.E + R1.N)>0){
                if (R1.Y == N - 1){
                    R1.Y = 0;
                    R1.F--;
                }else{
                    R1.Y++;
                    R1.F--;
                }
            }else{
                if (R1.X == M - 1){
                    R1.X = 0;
                    R1.F--;
                }else{
                    R1.X++;
                    R1.F--;
                }
            }
        }
        if (R2.F > 0){
            if (i % (R2.E + R2.N) <= R2.E&& i % (R2.E + R2.N) > 0){
                if (R2.X == M - 1){
                    R2.X = 0;
                    R2.F--;
                }else{
                    R2.X++;
                    R2.F--;
                }
            }else{
                if (R2.Y == N - 1){
                    R2.Y = 0;
                    R2.F--;
                }else{
                    R2.Y++;
                    R2.F--;
                }
            }
        }
        if (R1.Y == R2.Y && R1.X == R2.X){
            printf("robots explode at time %lld", i);
            explode++;
            break;
        }
        if (R1.F == 0 && R2.F == 0){
             break;
        }  
    }
    if(!explode){
        fputs("robots will not explode",stdout);
    }
    return 0;
}
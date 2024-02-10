#include <stdio.h>
#include <stdlib.h>
int factorial(int n,int m){
    int val=1,k;
    if(n>0&&m>0){
        for(k=n;k>n-m;k--){
            val*=k;
        } 
    }
    return val;
}
int main(int argc, char *argv[]) {
    int n,m,i,j,sum=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<=m;i++){
        sum+=factorial(n,i)/factorial(i,i-1);
    }
    printf("%d",sum);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("%d",j);
        }    
    }
    return 0;
}
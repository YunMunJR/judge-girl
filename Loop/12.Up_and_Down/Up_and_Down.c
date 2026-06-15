#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("%d\n",i);
    }
    for(i=n-1;i>0;i--){
        printf("%d\n",i);
    }
    return 0;
}
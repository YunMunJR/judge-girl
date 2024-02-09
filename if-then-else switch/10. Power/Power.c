#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int i,n;
    scanf("%d %d",&n,&i);
    if(i>=1&&i<=5){
        int val=pow(n,i);
        printf("%d",val);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n,i,m,k,t=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]); 
    }
    scanf("%d",&m);
    int r[m];
    for(i=0;i<m;i++){
        r[i]=0;
    }
    for(i=0;i<n;i++){
        k=a[i]%m;
        t=r[k];
        t++;
        r[k]=t;
        t=0;
    }
    for(i=0;i<m;i++){
        printf("%d\n",r[i]); 
    }
    return 0;
}
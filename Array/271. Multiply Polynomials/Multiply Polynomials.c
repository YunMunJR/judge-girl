#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int i,j,n,m,k,t1,t2,smaller,bigger,s;
    scanf("%d",&n);
    int a[n];
    for(i=n-1;i>=0;i--){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int b[m];    
    for(i=m-1;i>=0;i--){
        scanf("%d",&b[i]);
    }
    int sum[m+n-1];
    for(i=0;i<m+n-1;i++){
        sum[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            sum[i+j]+=a[i]*b[j];
        }  
    }
    for(i=m+n-2;i>=0;i--){
        printf("%d",sum[i]);
        (i>0)&&putchar(' ');
    }
    return 0;
} 
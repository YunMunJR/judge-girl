#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int i,j,n,m;
    scanf("%d %d",&n,&m);
    int a[n+2][m+2];
    for(i=0;i<n+2;i++){
        for(j=0;j<m+2;j++){
            a[i][j]=0;
        }  
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<m+1;j++){
            scanf("%d",&a[i][j]);
        }     
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<m+1;j++){
            if(a[i][j]>a[i-1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i][j+1]&&a[i][j]>a[i+1][j]){
                printf("%d\n",a[i][j]);
            }
        }
    }
    return 0;
}
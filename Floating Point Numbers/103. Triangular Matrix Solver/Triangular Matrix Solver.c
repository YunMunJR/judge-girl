#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n,i,j;
    scanf("%d",&n);
    double a[n][n],b[n],solution[n];
    for(i=0;i<n;i++)
    solution[i]=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&a[i][j]);
        }
    }  
    for(i=0;i<n;i++){
        scanf("%lf",&b[i]);
    }
    for(i=n-1;i>=0;i--){
        for(j=n-1;j>=i;j--){
            b[i]-=solution[j]*a[i][j];
        }
        solution[i]=b[i]/a[i][i];
    }
    for(i=0;i<n;i++){
        printf("%lf",solution[i]);
        (i!=n-1)&&putchar('\n');
    } 
    return 0;
}
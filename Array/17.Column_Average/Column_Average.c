#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int i,j,r,c,sum=0;
    scanf("%d %d",&r,&c);
    int a[r][c],avr[c];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }    
    }
    for(j=0;j<c;j++){
        for(i=0;i<r;i++){
            sum+=a[i][j];     
        }
        sum/=r;
        printf("%d\n",sum);
        sum=0;    
    }
    return 0;
}
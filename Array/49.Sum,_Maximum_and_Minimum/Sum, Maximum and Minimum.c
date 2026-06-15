#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int i,j,N,M,m=0,sum=0,maxi=0,mini=0,t=0,k;
    scanf("%d%d",&N,&M);
    static int a[1000][10000];
    static int num[10000];
    for(j=0;j<N;j++){
        scanf("%d",&num[j]);
    }
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            a[i][j]=0;
        }  
    }
    for(i=0;i<M;i++){
        sum=0;
        t=0;
        for(j=0;j<N;j++){
            if(num[j]%M==i){
                a[i][t]=num[j];
                t++;
            }
        }
        maxi=a[i][0];
        mini=a[i][0];
        for(k=0;k<t;k++){
            sum=sum+a[i][k];
            if(maxi<a[i][k]){
                maxi=a[i][k];
            }
            if(mini>a[i][k]){
                mini=a[i][k];
            }
        }
        printf("%d ",sum);
        printf("%d ",maxi);
        printf("%d\n",mini);
    }
    return 0;
}
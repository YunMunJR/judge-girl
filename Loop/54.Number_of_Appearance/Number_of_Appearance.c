#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int N,M,a[7],i,M1,j,num=0;
    scanf("%d %d",&N,&M);
    M1=M;
    for(i=6;i>=0;i--){
        a[i]=M1%10;
        M1=(M1-a[i])/10;
    }
    for(j=0;j<6;j++){
       (a[j]*10+a[j+1]==N)? num++:num; 
    }    
    printf("%d\n",num);
    return 0;
}
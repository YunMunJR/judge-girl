#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int adjcent(int num,int n){
    int a[4],i,j;
    a[0]=num/1000;
    num-=1000*a[0];
    a[1]=num/100;
    num-=100*a[1];
    a[2]=num/10;
    num-=10*a[2];
    a[3]=num;
    for(i=0;i<3;i++){
        if(abs(a[i]-a[i+1])>n){
            return 0;
        }
    }
    return 1;
}
int main(int argc, char *argv[]) {
    int digit,k=0,a[100]={0},i,j;
    scanf("%d",&j);
    for(i=1000;i<10000;i++){
        (adjcent(i,j))&&printf("%d\n",i);
    }    
    return 0;
}
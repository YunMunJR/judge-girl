#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
    int w,a,b,c,d,e;
    int length_square;
    scanf("%d%d%d%d%d%d",&w,&a,&b,&c,&d,&e);
    int k=(d>e)?d:e ;
    if(b>0){
        length_square=pow((a+2*d+b+2*e+c+2),2)+w*w;
    }else{
        length_square=pow((a+2+c+2*k),2)+w*w;
    }
    printf("%d",length_square);    
    return 0;
}
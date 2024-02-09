#include <stdio.h>
#include <math.h>
int main(int argc, char** argv) {
    int x,sum=0;
    scanf("%d",&x);
    if(x>0){
        if(x%3==0){
            sum+=3;
        }
        if(x%5==0){
            sum+=5;
        }
        if(x>=100&&x<=200){
            sum+=50;
        }else{
            sum-=50;
        }
    }else{
        sum=-100;
    }
    printf("%d\n",sum);
    return 0;
}
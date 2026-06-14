#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n;
    scanf("%d",&n);
    if(n%15==0&&n%7!=0){
        fputs("0\n",stdout);
    }else{
        fputs("1\n",stdout);
    }
}
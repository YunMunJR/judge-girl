#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
    int a;
    scanf("%d",&a);
    if(a<0)
    a=-a;
    int d=a/100;
    a=a-d*100;
    printf("%d\n",d);
    int n=a/10;
    printf("%d\n",n);
    a=a-n*10;
    printf("%d\n",a);
    return 0;
}
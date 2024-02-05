#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
 
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",2*(a*b+b*c+c*a));
    printf("%d\n",(a*b*c));
 
    return 0;
}
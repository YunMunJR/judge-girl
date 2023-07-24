#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int a[12],i;
    for(i=0;i<8;i++)
    scanf("%d",&a[i]);
    for(i=0;i<3;i++)
    a[i+8]=a[i*2]*a[2*i+3]-a[2*i+1]*a[2*i+2];
    a[11]=a[6]*a[1]-a[0]*a[7];
    if(a[8]>0&&a[9]>0&&a[10]>0&&a[11]>0)
    printf("1\n");
    else
    printf("0\n");
    return 0;
}
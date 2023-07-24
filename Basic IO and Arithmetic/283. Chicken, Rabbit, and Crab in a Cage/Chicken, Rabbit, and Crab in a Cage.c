#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int s,f,t;
    scanf("%d %d %d",&s,&f,&t);
    if(t<=s)
    {
    int crab=s-t;
    f=f-8*crab;
    if(f>=2*t&&f%2==0)
    {
    int rabbit=(f-2*t)/2;
    int chick=t-rabbit;
    printf("%d\n",chick);
    printf("%d\n",rabbit);
    printf("%d\n",crab);
    }
    else
    printf("0\n");
    }
    else
    printf("0\n");
    return 0;
}
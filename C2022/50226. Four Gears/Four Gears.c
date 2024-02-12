#include <stdio.h>
#include <stdlib.h> 
int lcm(int a,int b){
    int k=1,a1,b1;
    a1=a;b1=b;
    while(k!=0){
        k=a1%b1;
        a1=b1;
        b1=k;
    }
    if(a>b){
        return (a/a1)*b;
    }else{
        return a*(b/a1);
    }
}
int main(int argc, char *argv[]) {
    int a,b,c,d,n;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
        n=lcm(a,lcm(b,lcm(c,d)))/a;
        printf("%d\n",n);
    } 
    return 0;
}
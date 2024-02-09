#include <stdio.h>
int main(int argc, char** argv) {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a+b>c&&b+c>a&&c+a>b){
        fputs("1\n",stdout);
    }else{
        fputs("0\n",stdout);
    }
    return 0;
}
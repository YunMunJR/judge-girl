#include <stdio.h>
int main(int argc, char** argv) {
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    int a_ = a - 2*e, b_ = b - 2*e, c_ = c - 2*e;
    int out_area = 2 * (a * b + b * c + c * a);
    int in_area = 8 * d * (a_ + b_ + c_);
    int vol = a * b * c - 2 * d * (a_ * b_ + b_ * c_ + c_ * a_);
    printf("%d\n", out_area+in_area);
    printf("%d\n",vol);
 

    return 0;
}
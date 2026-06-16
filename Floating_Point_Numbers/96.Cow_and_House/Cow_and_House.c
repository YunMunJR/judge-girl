#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    double pi=3.1415926;
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double area1=(c>a)?(c-a)*(c-a)*pi/4 : 0;
    double area2=(c>b)?(c-b)*(c-b)*pi/4 : 0;
    double areasum=(3*c*c*pi)/4+area1+area2;
    printf("%f",areasum);     
    return 0;
}
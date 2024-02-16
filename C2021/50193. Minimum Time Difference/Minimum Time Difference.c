#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct time{
    int s;
    int m;
    int h;
}time;
int main(int argc, char *argv[]) {
    int n,num,second_min,second,i;
    n=0;
    second_min=0;
    time t[500];
    while(scanf("%d",&num)!=EOF){
        t[n].s=num%100;
        num=(num-t[n].s)/100;
        t[n].m=num%100;
        t[n].h=(num-t[n].m)/100;
        n++;    
    }
    int s[n];
    for(i=0;i<n;i++){
        s[i]=3600*t[i].h+60*t[i].m+t[i].s;
    }
    second_min=abs(s[1]-s[0]);
    for(i=1;i<n;i++){
        second=abs(s[i]-s[i-1]);
        second_min=(second<second_min)?second:second_min;   
    }
    printf("%d",second_min);    
    return 0;
}
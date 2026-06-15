#include <stdio.h>
#include <stdlib.h>
typedef struct coordin{
   int x,y;
}coordin;
int main(int argc, char *argv[]) {
    int i,t=0;
    coordin a[200]={0,0},max,min;
    while(scanf("%d%d",&a[t].x,&a[t].y)!=EOF){ 
        t++;
    } 
    max.x=a[0].x;
    max.y=a[0].y;
    min.x=a[0].x;
    min.y=a[0].y;
    for(i=0;i<t;i++){
        if(max.x<a[i].x){
            max.x=a[i].x;
        }
        if(max.y<a[i].y){
            max.y=a[i].y;
        }
        if(min.x>a[i].x){
            min.x=a[i].x;
        }
        if(min.y>a[i].y){
            min.y=a[i].y;
        } 
    }
    printf("%d",(max.x-min.x)*(max.y-min.y));
    return 0;
}
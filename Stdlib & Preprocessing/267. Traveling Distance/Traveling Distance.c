#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x;
    int y;
    int d;
}coor;
int dcount(int a,int b){
    return a*a+b*b;
}
int cmp(const void*a,const void*b){
    coor c=*(coor*)a,d=*(coor*)b;
    if(c.d!=d.d){
        if(c.d>d.d){
            return 1;
        }else{
            return -1;
        }
    }else{
        if(c.x!=d.x){
            if(c.x>d.x){
                return 1;
            }else{
                return -1;
            }
        }else{
            if(c.y>d.y){
                return 1;
            }else{
                return -1;
            }
        }
    }
}
int main(){
    coor d[100000];
    int c=0;
    while(scanf("%d%d",&d[c].x,&d[c].y)!=EOF){
        d[c].d=dcount(d[c].x,d[c].y);
        c++;
    }
    qsort(d,c,sizeof(coor),cmp);
    int distance=d[0].x*d[0].x+d[0].y*d[0].y;
    for(int i=1;i<c;i++){
        distance+=dcount((d[i].x-d[i-1].x),(d[i].y-d[i-1].y));
    }
    printf("%d\n",distance);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct coordinate_system{
   int x,y,c;
}parking_lots;
typedef struct coordinate_system2{
    int x,y;
}bycicles;
typedef struct capacity{
    int c;
}cap;
int main(int argc, char *argv[]) {    
    int n,m,i,j,min,minnum,k;
    scanf("%d",&n);    
    parking_lots pl[n];
    for(i=0;i<n;i++){
        scanf("%d%d%d",&pl[i].x,&pl[i].y,&pl[i].c);
    }
    scanf("%d\n",&m);
    bycicles b[m],mini[m];    
    for(i=0;i<m;i++){
        scanf("%d%d",&b[i].x,&b[i].y);
    }
    cap ca[n];
    for(i=0;i<n;i++){
        ca[i].c=0;
    }
    for(i=0;i<m;i++){        
        minnum=0;k=0;
        while(ca[k].c==pl[k].c){    
            k++;
        }
        min=abs(b[i].x-pl[k].x)+abs(b[i].y-pl[k].y);
        mini[i].x=pl[k].x;mini[i].y=pl[k].y;
        for(j=k;j<n;j++){    
            if(pl[j].c>ca[j].c){
                if(min>abs(b[i].x-pl[j].x)+abs(b[i].y-pl[j].y)){
                    min=abs(b[i].x-pl[j].x)+abs(b[i].y-pl[j].y);
                    mini[i].x=pl[j].x;mini[i].y=pl[j].y;
                    minnum=j;
                }else if(min==abs(b[i].x-pl[j].x)+abs(b[i].y-pl[j].y)){
                    if(pl[j].x<=mini[i].x){    
                        mini[i].x=pl[j].x;mini[i].y=pl[j].y;
                        minnum=j;
                    }
                }
            }    
        }
        ca[minnum].c++;
    }            
    for(i=0;i<n;i++){
        printf("%d",ca[i].c);
        (i!=n-1)&&putchar('\n');   
    }
    return 0;
}
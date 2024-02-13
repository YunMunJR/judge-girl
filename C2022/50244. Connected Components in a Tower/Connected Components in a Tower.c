#include <stdio.h>
#include <stdint.h>
#define MAXN 80
typedef struct{
    int numbernum;
    int maxrepeatnum;
    int maxrepeatidx;
}Data;
int solve(int cubic[MAXN][MAXN][MAXN],int key,int lay,int i,int j,int k){
    //fprintf(stdout,"%d %d %d\n",i,j,k);
    if(i<0||j<0||k<0||i>=lay||j>i||k>i){
        return 0;
    }else{
        if(cubic[i][j][k]!=key){
            return 0;
        }else if(cubic[i][j][k]==0){
            return 0;
        }else{
            cubic[i][j][k]=0;
            return 1+solve(cubic,key,lay,i+1,j,k)+solve(cubic,key,lay,i-1,j,k)+solve(cubic,key,lay,i,j+1,k)
                    +solve(cubic,key,lay,i,j-1,k)+solve(cubic,key,lay,i,j,k+1)+solve(cubic,key,lay,i,j,k-1);
        }
    }
}
int main(){
    int cubic[MAXN][MAXN][MAXN];
    int lay,find;
    scanf("%d",&lay);
    Data d;
    d.numbernum=0;
    d.maxrepeatnum=INT32_MIN;
    for(int i=1;i<=lay;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                scanf("%d",&cubic[i-1][j][k]);
            }
        }
    }
    for(int i=1;i<=lay;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                if(cubic[i-1][j][k]!=0){
                    int numidx=cubic[i-1][j][k];
                    int repeatnum=solve(cubic,numidx,lay,i-1,j,k);  
                    (d.maxrepeatnum<repeatnum)&&((d.maxrepeatnum=repeatnum)&&(d.maxrepeatidx=numidx));
                    (d.maxrepeatnum==repeatnum&&d.maxrepeatidx<numidx)&&(d.maxrepeatidx=numidx);
                }
            } 
       }
    }
    printf("%d %d\n",d.maxrepeatidx,d.maxrepeatnum);
    return 0;
}

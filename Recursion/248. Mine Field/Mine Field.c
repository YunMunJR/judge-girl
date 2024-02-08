#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int num;
    int can;
}data;
void exe(data map[11][11],int mine[11][11],int c,int r){
    mine[c][r]--;
    for(int i=c-1;i<c+2;i++){
        for(int j=r-1;j<r+2;j++){
            if(map[i][j].can){
                map[i][j].num++;
            }
        }
    }
}
int solve(data map[11][11],int mine[11][11],int idx,int put){
    int c=(idx/9)+1,r=(idx%9)+1;
    int col=(idx+18)/9+1,row=(idx+18)%9+1;
    if(put){
        mine[c][r]++;
        int fail=0;
        for(int i=c-1;i<c+2;i++){
            for(int j=r-1;j<r+2;j++){
                if(map[i][j].can){
                    map[i][j].num--;
                    if(map[i][j].num<0){
                        fail=1;
                    }
                }           
            }
        }
        if(fail){           
            return 0;
        }
    }
    if(idx<63){
        if(map[col][row].num!=0){
            return 0;
        }else{
            if(idx==0){
                for(int i=17;i>=0;i--){
                    int co=i/9+1,ro=i%9+1;
                    if(map[co][ro].num!=0){
                        return 0;
                    }
                }
                for(int i=1;i<10;i++){
                    for(int j=1;j<10;j++){
                        printf("%d",mine[i][j]);
                        (j!=9)&&putchar(' ');     
                    }
                    putchar('\n');
                }
                return 1;
            }else{
                if(!solve(map,mine,idx-1,1)){
                    int cc=(idx-1)/9+1,rr=(idx-1)%9+1;
                    exe(map,mine,cc,rr);
                    return solve(map,mine,idx-1,0);
                }else{
                    return 1;
                }
            }
        }   
    }else{
        if(!solve(map,mine,idx-1,1)){
            int cc=(idx-1)/9+1,rr=(idx-1)%9+1;
            exe(map,mine,cc,rr);
            return solve(map,mine,idx-1,0);
        }else{
            return 1;
        }
    }  
}
int main(int argc,char**argv){
    data map[11][11];
    int mine[11][11];
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){          
            if(i==0||i==10||j==0||j==10){
                map[i][j].can=0;
            }else{
                scanf("%d",&map[i][j].num);
                map[i][j].can=1;
            }
            mine[i][j]=0;
        }
    }
    int s=1;
    if(!solve(map,mine,80,1)){
        exe(map,mine,9,9);
        s=solve(map,mine,80,0);
    }
    if(!s){
        fputs("no solution\n",stdout);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXN 100
typedef struct{
    int x;
    int y;
    int z;
    int empty;
}data;
typedef struct{
    int x1;
    int y1;
    int z1;
    int x2;
    int y2;
    int z2;
}repeat;
int max(int a,int b){
    return (a>b)?a:b;
}
int f(char *s,int K){
    int re=(int)(s[0]-'a')+1;
    for(int i=1;i<strlen(s);i++){
       re*=29;
       re+=(int)(s[i]-'a'); 
       re++;   
    }
    return re%K;
}
int main(){
    int N,K,C;  
    repeat re;
    char cubic[MAXN][MAXN][MAXN][6];
    scanf("%d",&N);
    K=N*N;C=10;
    data hash[K][C];
    int repeat=0,hashcount[K];
    for(int i=0;i<K;i++){
        hashcount[i]=0;
        for(int j=0;j<C;j++){
            hash[i][j].empty=1; 
            hash[i][j].x=-1;
            hash[i][j].y=-1;
            hash[i][j].z=-1;    
        }
    } 
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=i;k++){
                scanf("%s",cubic[i][j][k]);
                if(j==i||k==i){
                    repeat=0;                       
                    int idx=f(cubic[i][j][k],K);
                    for(int ii=0;ii<hashcount[idx];ii++){
                        if(!strcmp(cubic[hash[idx][ii].x][hash[idx][ii].y][hash[idx][ii].z],cubic[i][j][k])&&!hash[idx][ii].empty){                
                            repeat=1;
                            re.x1=i;re.y1=j;re.z1=k;
                            re.x2=hash[idx][ii].x;
                            re.y2=hash[idx][ii].y;
                            re.z2=hash[idx][ii].z;
                            hash[idx][ii].empty=1;
                            break;
                        }
                    }
                    if(!repeat){
                        hash[idx][hashcount[idx]].x=i;
                        hash[idx][hashcount[idx]].y=j;
                        hash[idx][hashcount[idx]].z=k;
                        hash[idx][hashcount[idx]].empty=0;
                        hashcount[idx]++;
                    }         
                }
            }          
        }
    }
    repeat=1;
    int idx1,idx2;
    while(repeat){
        repeat=0;       
        printf("%s\n",cubic[re.x1][re.y1][re.z1]);         
        if(re.x1<N-1){
            re.x1++;
            idx1=f(cubic[re.x1][re.y1][re.z1],K);           
            for(int ii=0;ii<C;ii++){               
                int x=hash[idx1][ii].x,y=hash[idx1][ii].y,z=hash[idx1][ii].z;
                if(!strcmp(cubic[x][y][z],cubic[re.x1][re.y1][re.z1])&&!hash[idx1][ii].empty){                
                    repeat=1;                
                    if(re.x2<N-1){
                        re.x2++;
                        idx2=f(cubic[re.x2][re.y2][re.z2],K);
                        for(int ii=0;ii<C;ii++){
                            if(hash[idx2][ii].empty){
                                hash[idx2][ii].x=re.x2;
                                hash[idx2][ii].y=re.y2;
                                hash[idx2][ii].z=re.z2;
                                hash[idx2][ii].empty=0;
                                break;
                            }
                        }
                    }                                  
                    re.x2=hash[idx1][ii].x;
                    re.y2=hash[idx1][ii].y;
                    re.z2=hash[idx1][ii].z;
                    hash[idx1][ii].empty=1;
                    break;
                }
            }
            if(!repeat){ // re.x1 doesn't find repeat
                for(int ii=0;ii<C;ii++){
                    if(hash[idx1][ii].empty){
                        hash[idx1][ii].x=re.x1;
                        hash[idx1][ii].y=re.y1;
                        hash[idx1][ii].z=re.z1;
                        hash[idx1][ii].empty=0;            
                        break;
                    }
                }
                if(re.x2<N-1){                  
                    re.x2++;
                    idx2=f(cubic[re.x2][re.y2][re.z2],K);
                    for(int ii=0;ii<C;ii++){
                        int x=hash[idx2][ii].x,y=hash[idx2][ii].y,z=hash[idx2][ii].z;
                        if(!strcmp(cubic[x][y][z],cubic[re.x2][re.y2][re.z2])&&!hash[idx2][ii].empty){                
                            repeat=1;                   
                            re.x1=hash[idx2][ii].x;
                            re.y1=hash[idx2][ii].y;
                            re.z1=hash[idx2][ii].z;
                            hash[idx2][ii].empty=1;
                            break;
                        }
                    }           
                }              
            }
        }
        else{
            if(re.x2<N-1){
                re.x2++;
                idx2=f(cubic[re.x2][re.y2][re.z2],K);
                for(int ii=0;ii<C;ii++){
                    int x=hash[idx2][ii].x,y=hash[idx2][ii].y,z=hash[idx2][ii].z;
                    if(!strcmp(cubic[x][y][z],cubic[re.x2][re.y2][re.z2])&&!hash[idx2][ii].empty){                
                        repeat=1;                   
                        re.x1=hash[idx2][ii].x;
                        re.y1=hash[idx2][ii].y;
                        re.z1=hash[idx2][ii].z;
                        hash[idx2][ii].empty=1;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
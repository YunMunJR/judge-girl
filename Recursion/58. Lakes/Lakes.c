#include <stdio.h>
int find_lake(int lake[400][400],int N,int M,int init_x,int init_y){
    if (init_x < 0 || init_y < 0 || init_x >= N || init_y >= M){
        return 0;
    }else{
        if (lake[init_x][init_y] == 0){
            return 0;
        }else{
            lake[init_x][init_y]=0;
            return(1 + find_lake(lake, N, M, init_x + 1, init_y) + find_lake(lake, N, M, init_x, init_y + 1) + find_lake(lake, N, M, init_x - 1, init_y) + find_lake(lake, N, M, init_x, init_y - 1));
        }
    }
}
int main(){
    int N, M,num=0,temp;
    static int lake[400][400] = { 0 },lake_num[1000]={0};
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%d", &lake[i][j]);
        }    
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (lake[i][j] != 0){
                lake_num[num] = find_lake(lake, N, M, i, j);
                num++;
            }
        }
    }
    for (int i = num-1; i >0; i--){
        for (int j = 0; j < i; j++){
            if (lake_num[j] < lake_num[j + 1]){
                temp = lake_num[j]; lake_num[j] = lake_num[j + 1]; lake_num[j + 1] = temp;
            }
        }
    }
    for(int i=0;i<num;i++){
        printf("%d\n",lake_num[i]);
    }
    return 0;
}
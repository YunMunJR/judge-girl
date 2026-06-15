#include <stdio.h>
#include <stdlib.h>
int bingo(int m1,int j1,int a1[10][256][256],int i3,int j3){    
    int line = 1, dia1 = 1, col = 1, dia2 = 1,result = 0;
        for (int j = 0; j < m1; j++){
            if (a1[j1][i3][j] != 0){
                line = 0;
            }
            if (a1[j1][j][j3] != 0){
                col = 0;
            }     
        }
        for (int j = 0; j < m1; j++){
            if (a1[j1][j][j] != 0){
                dia1 = 0;
            }
        }
        for (int j = 0; j < m1; j++){
            if (a1[j1][m1 - j - 1][j] != 0){
                dia2 = 0;
            }
        }
        result = dia1 == 1 || col == 1 || line == 1 || dia2 == 1;
    return result;
}
int main(){
    int n, m, playnum,j2=0,i2=0,f=0,n1,m1;
    char ch = '0';
    scanf("%d%d", &n, &m);
    char players[10][66] = { '\0' };
    int a[10][256][256]={0};
    int pl[10] = { 10,10,10,10,10,10,10,10,10,10 }, t = 0;
    static int  num2[10][256*256][2]={0}, num[256 * 256] = { 0 };
    int* ptr[10][256 * 256];
    scanf("%c", &ch);
    for (int i = 0; i < n; i++){
        scanf("%s", players[i]);
        for (int j = 0; j < m; j++){
            for (int k = 0; k < m; k++){
                scanf("%d", &a[i][j][k]);
                ptr[i][a[i][j][k]] = &a[i][j][k];
                num2[i][a[i][j][k]][0] = j;
                num2[i][a[i][j][k]][1] = k;
            }
        }
    }
    for (int i = 0; i < m * m; i++){
        scanf("%d", &num[i]); 
        playnum = 0;
        for (int j = 0; j < n; j++){
            if (j != pl[0] && j != pl[1] && j != pl[2] && j != pl[3] && j != pl[4] && j != pl[5] && j != pl[6] && j != pl[7] && j != pl[8] && j != pl[9]){
                *ptr[j][num[i]] = 0;
                n1 = num2[j][num[i]][0]; m1 = num2[j][num[i]][1];
                    if (bingo(m, j, a,n1,m1)){
                        if (playnum == 0){
                            if (f > 0){
                                putchar('\n');
                                printf("%d %s", num[i], players[j]); 
                                pl[t] = j; 
                                t++; 
                                playnum++;
                            }else{
                                printf("%d %s", num[i], players[j]); 
                                pl[t] = j; 
                                t++; 
                                playnum++;
                            }         
                        }else{
                            printf(" %s", players[j]); 
                            pl[t] = j; 
                            t++; 
                            playnum++;
                        }
                    }
            }
        }
        if (playnum != 0){
            break;
        }    
    }
    return 0;
}
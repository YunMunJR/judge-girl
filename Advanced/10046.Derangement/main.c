#include <stdio.h>
#include <string.h>
int n, m;
int ban[10][10];
int used[10];
char ans[11];
void dfs(int pos){
    if(pos == n){
        ans[n] = '\0';
        printf("%s\n", ans);
        return;
    }
    for(int i=0;i<n;i++){
        if(used[i]) continue;
        if(ban[i][pos]) continue;
        used[i] = 1;
        ans[pos] = 'A' + i;
        dfs(pos + 1);
        used[i] = 0;
    }
}

int main(){
    while(scanf("%d%d", &n, &m) == 2){
        memset(ban, 0, sizeof(ban));
        memset(used, 0, sizeof(used));
        for(int i=0;i<m;i++){
            int x, y;
            scanf("%d%d", &x, &y);
            --x;
            --y;
            ban[x][y] = 1;
        }
        dfs(0);
    }
    return 0;
}
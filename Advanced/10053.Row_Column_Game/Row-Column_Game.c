#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int ret[3], g[4][4], used[4][4] = {}, n;
void dfs(int u, int x, int a, int b) {
    int end = 1;
    if (u == 0) {
        for (int i = 0; i < n; i++) {
            if (used[x][i])    continue;
            used[x][i] = 1;
            dfs(!u, i, a+g[x][i], b);
            used[x][i] = 0;
            end = 0;
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (used[i][x])    continue;
            used[i][x] = 1;
            dfs(!u, i, a, b+g[i][x]);
            used[i][x] = 0;
            end = 0;
        }
    }
    if (end) {
        if (a > b)        ret[0]++;
        else if (a < b)    ret[1]++;
        else            ret[2]++;
    }
}
int main() {
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &g[i][j]);
        memset(ret, 0, sizeof(ret));
        dfs(0, 0, 0, 0);
        printf("%d %d %d\n", ret[0], ret[1], ret[2]);
    }
    return 0;
}
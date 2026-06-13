#include <stdio.h>

#define MAXN 1005
#define MAXM 1005
#define MAXANS 1000005

int nxt[MAXN][MAXM];
int ansx[MAXANS], ansy[MAXANS];

int find_next(int row, int y) {
    if (nxt[row][y] == y) return y;
    return nxt[row][y] = find_next(row, nxt[row][y]);
}

int main() {
    int N, M, Q;
    scanf("%d %d", &N, &M);
    scanf("%d", &Q);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M + 1; j++) {
            nxt[i][j] = j;
        }
    }
    
    while (Q--) {
        int lx, ly, rx, ry;
        scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
        int cnt = 0;
        for (int x = lx; x <= rx; x++) {
            int y = find_next(x, ly);
            while (y <= ry) {
                ansx[cnt] = x;
                ansy[cnt] = y;
                cnt++;

                nxt[x][y] = find_next(x, y + 1);
                y = find_next(x, y);
            }
        }
        printf("%d", cnt);
        for (int i = 0; i < cnt; i++) {
            printf(" (%d, %d)", ansx[i], ansy[i]);
        }
        printf("\n");
    }

    return 0;
}
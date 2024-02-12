#include <stdio.h>
typedef struct repeat {
    int i1, j1, k1, i2, j2, k2;
}Repeat;
typedef struct exsit {
    int exsit1, exsit2;
}Exsit;
int hashf(int k, int S) {
    return((77 * k + 2222) % S);
}
int find_number(int N,int i, int j, int k, int cubic[106][106][106]) {
    int re = 0;
    for (int ii = i; ii < N; ii++) {
        if (cubic[ii][j][k] != 0) { re = cubic[ii][j][k]; break; }
    }
    return re;
}
int find_layer(int N, int i, int j, int k, int cubic[106][106][106])  {
    int re = -1;
    for (int ii = i; ii < N; ii++) {
        if (cubic[ii][j][k] != 0) { re = ii; break; }
    }
    return re;
}
int main() {
    int exsit = 0, pair = 0; Exsit ex = { 0,0 };
    static int cubic[106][106][106], hash[11025][10][4]; 
    Repeat r = { -1,-1,-1,-1,-1,-1 };
    int N, S, C, record1, record2, n = 0;
    scanf("%d%d%d", &N, &S, &C);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                scanf("%d", &cubic[i][j][k]);
                if (j == i || k == i) {
                    for (int ii = 0; ii < C; ii++) {
                        if (hash[hashf(cubic[i][j][k], S)][ii][0] == cubic[i][j][k]) {
                            n = cubic[i][j][k];
                            r.i1 = hash[hashf(cubic[i][j][k], S)][ii][1]; 
                            r.j1 = hash[hashf(cubic[i][j][k], S)][ii][2]; 
                            r.k1 = hash[hashf(cubic[i][j][k], S)][ii][3];
                            r.i2 = i; 
                            r.j2 = j; 
                            r.k2 = k;
                            hash[hashf(cubic[i][j][k], S)][ii][0] = 0; hash[hashf(cubic[i][j][k], S)][ii][1] = 0;
                            hash[hashf(cubic[i][j][k], S)][ii][2] = 0; hash[hashf(cubic[i][j][k], S)][ii][3] = 0;
                            cubic[r.i1][r.j1][r.k1] = 0; cubic[r.i2][r.j2][r.k2] = 0;
                            pair = 1; exsit = 1; 
                            break;
                        }
                    }
                    if (!exsit) {
                        for (int ii = 0; ii < C; ii++) {
                            if (hash[hashf(cubic[i][j][k], S)][ii][0] == 0) {
                                hash[hashf(cubic[i][j][k], S)][ii][0] = cubic[i][j][k];
                                hash[hashf(cubic[i][j][k], S)][ii][1] = i;
                                hash[hashf(cubic[i][j][k], S)][ii][2] = j;
                                hash[hashf(cubic[i][j][k], S)][ii][3] = k; 
                                break;
                            }
                        }
                    }
                }
                exsit = 0;
            }
        }
    }
    printf("%d ", n);
    while (pair) {
        pair = 0; ex.exsit1 = 0; ex.exsit2 = 0;
        for (int ii = 0; ii < C; ii++) {
            if (hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][ii][0] == find_number(N, r.i1, r.j1, r.k1, cubic) && find_number(N, r.i1, r.j1, r.k1, cubic) > 0){
                ex.exsit1 = 1; record1 = ii;
            }
        }
        if (ex.exsit1) {
            for (int ii = 0; ii < C; ii++) {
                if (hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][ii][0] == 0) {
                    hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][ii][0] = find_number(N, r.i2, r.j2, r.k2, cubic);
                    hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][ii][1] = r.i2;
                    hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][ii][2] = r.j2;
                    hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][ii][3] = r.k2; 
                    break;
                }
            }
            pair = 1; printf("%d ", find_number(N, r.i1, r.j1, r.k1, cubic));
            r.i2 = hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][record1][1];
            r.j2 = hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][record1][2];
            r.k2 = hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][record1][3];
            hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][record1][0] = 0;
            hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][record1][1] = 0;
            hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][record1][2] = 0;
            hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][record1][3] = 0;
            cubic[find_layer(N, r.i1, r.j1, r.k1, cubic)][r.j1][r.k1] = 0; cubic[find_layer(N, r.i2, r.j2, r.k2, cubic)][r.j2][r.k2] = 0;
        }else {
            for (int ii = 0; ii < C; ii++) {
                if (hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][ii][0] == 0) {
                    hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][ii][0] = find_number(N, r.i1, r.j1, r.k1, cubic);
                    hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][ii][1] = r.i1;
                    hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][ii][2] = r.j1;
                    hash[hashf(find_number(N, r.i1, r.j1, r.k1, cubic), S)][ii][3] = r.k1; 
                    break;
                }
            }
            for (int ii = 0; ii < C; ii++) {
                if (hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][ii][0] == find_number(N, r.i2, r.j2, r.k2, cubic) && find_number(N, r.i2, r.j2, r.k2, cubic) > 0){
                    ex.exsit2 = 1; record2 = ii;
                }
            }
            if (ex.exsit2) {
                pair = 1; printf("%d ", find_number(N, r.i2, r.j2, r.k2, cubic));
                r.i1 = hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][record2][1];
                r.j1 = hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][record2][2];
                r.k1 = hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][record2][3];
                hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][record2][0] = 0;
                hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][record2][1] = 0;
                hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][record2][2] = 0;
                hash[hashf(find_number(N, r.i2, r.j2, r.k2, cubic), S)][record2][3] = 0;
                cubic[find_layer(N, r.i1, r.j1, r.k1, cubic)][r.j1][r.k1] = 0; 
                cubic[find_layer(N, r.i2, r.j2, r.k2, cubic)][r.j2][r.k2] = 0;
            }
        }
    }
    return 0;
}
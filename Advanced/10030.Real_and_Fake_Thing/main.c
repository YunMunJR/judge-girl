#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAXN 1024
#define MAXM 512
#define WORDS 8   // 512 / 64

uint64_t a[MAXN][WORDS];

int popcount64(uint64_t x) {
    return __builtin_popcountll(x);
}

int main() {
    int N, M;
    char s[MAXM + 5];

    while (scanf("%d %d", &N, &M) == 2) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < N; i++) {
            scanf("%s", s);
            for (int j = 0; j < M; j++) {
                if (s[j] == '1') {
                    int w = j / 64;
                    int b = j % 64;
                    a[i][w] |= (1ULL << b);
                }
            }
        }

        long long good = 0;
        long long total = 1LL * N * (N - 1) / 2;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int inter = 0;
                int uni = 0;
                for (int k = 0; k < WORDS; k++) {
                    uint64_t x = a[i][k];
                    uint64_t y = a[j][k];
                    inter += popcount64(x & y);
                    uni   += popcount64(x | y);
                }

                if (5LL * inter >= 4LL * uni) {
                    good++;
                }
            }
        }
        printf("%.2f\n", 100.0 * good / total);
    }

    return 0;
}
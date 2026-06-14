#include <stdio.h>

int dp[105][105];
int a[105][105];

int main() {
    int N, M;

    while (scanf("%d%d", &N, &M) == 2) {

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &a[i][j]);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                dp[i][j] = 0;

        if (a[0][0] == 0)
            dp[0][0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

                if (a[i][j])
                    continue;

                if (i > 0)
                    dp[i][j] += dp[i - 1][j];

                if (j > 0)
                    dp[i][j] += dp[i][j - 1];

                dp[i][j] %= 10000;
            }
        }

        printf("%d\n", dp[N - 1][M - 1]);
    }

    return 0;
}
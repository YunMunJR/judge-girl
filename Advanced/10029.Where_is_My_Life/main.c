#include <stdio.h>
#include <math.h>

#define MAXN 105
#define EPS 1e-9

double a[MAXN][MAXN];
double q[MAXN];
int pivot_col[MAXN];

int main() {
    int N, M;

    while (scanf("%d %d", &N, &M) == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= M; j++) {
                scanf("%lf", &a[i][j]);
            }
        }

        for (int i = 0; i < M; i++) {
            scanf("%lf", &q[i]);
        }

        int rank = 0;

        for (int col = 0; col < M; col++) {
            int sel = -1;

            for (int row = rank; row < N; row++) {
                if (fabs(a[row][col]) > EPS) {
                    sel = row;
                    break;
                }
            }

            if (sel == -1) continue;

            for (int j = col; j <= M; j++) {
                double tmp = a[rank][j];
                a[rank][j] = a[sel][j];
                a[sel][j] = tmp;
            }

            double div = a[rank][col];
            for (int j = col; j <= M; j++) {
                a[rank][j] /= div;
            }

            for (int row = 0; row < N; row++) {
                if (row == rank) continue;

                double factor = a[row][col];
                if (fabs(factor) < EPS) continue;

                for (int j = col; j <= M; j++) {
                    a[row][j] -= factor * a[rank][j];
                }
            }

            pivot_col[rank] = col;
            rank++;
        }

        int contradictory = 0;

        for (int i = rank; i < N; i++) {
            if (fabs(a[i][M]) > EPS) {
                contradictory = 1;
                break;
            }
        }

        if (contradictory) {
            printf("contradictory\n");
            continue;
        }

        int is_pivot[MAXN] = {0};
        for (int i = 0; i < rank; i++) {
            is_pivot[pivot_col[i]] = 1;
        }

        double ans = 0;

        for (int i = 0; i < rank; i++) {
            int pc = pivot_col[i];
            ans += q[pc] * a[i][M];
        }

        int not_sure = 0;

        for (int free_col = 0; free_col < M; free_col++) {
            if (is_pivot[free_col]) continue;

            double coef = q[free_col];

            for (int i = 0; i < rank; i++) {
                int pc = pivot_col[i];
                coef -= q[pc] * a[i][free_col];
            }

            if (fabs(coef) > EPS) {
                not_sure = 1;
                break;
            }
        }

        if (not_sure) {
            printf("not sure\n");
        } else {
            long long rounded;

            if (ans >= 0) rounded = (long long)(ans + 0.5);
            else rounded = (long long)(ans - 0.5);

            printf("%lld\n", rounded);
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 8
#define SAMPLE 2000000

typedef struct {
    double x, y;
} Point;

double frandom() {
    return rand() * 1.0 / RAND_MAX;
}

int main(void) {
    int N;
    double A, B;
    Point p[MAXN];
    int tc = 1;

    while (scanf("%d %lf %lf", &N, &A, &B) == 3) {
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }

        int cnt[MAXN] = {0};
        for (int s = 0; s < SAMPLE; s++) {
            double x = frandom() * A;
            double y = frandom() * B;

            int best = 0;
            double bestd = (x - p[0].x) * (x - p[0].x)
                         + (y - p[0].y) * (y - p[0].y);

            for (int i = 1; i < N; i++) {
                double d = (x - p[i].x) * (x - p[i].x)
                         + (y - p[i].y) * (y - p[i].y);

                if (d < bestd) {
                    bestd = d;
                    best = i;
                }
            }
            cnt[best]++;
        }

        printf("Case #%d:\n", tc++);

        for (int i = 0; i < N; i++) {
            int ans = (int)(cnt[i] * 100.0 / SAMPLE + 0.5);
            printf("%d\n", ans);
        }
    }

    return 0;
}
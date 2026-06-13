#include <stdio.h>
#include <stdlib.h>

#define MAXN 8
#define SAMPLE 3250000

typedef struct {
    double x, y, z;
} Point;

double frandom(void) {
    return rand() * 1.0 / RAND_MAX;
}

double dist2(Point a, double x, double y, double z) {
    double dx = x - a.x;
    double dy = y - a.y;
    double dz = z - a.z;
    return dx * dx + dy * dy + dz * dz;
}

int main(void) {
    int R, N;
    Point p[MAXN];
    int tc = 1;

    while (scanf("%d %d", &R, &N) == 2) {
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
        }

        int cnt[MAXN] = {0};

        for (int s = 0; s < SAMPLE; s++) {
            double x, y, z;

            do {
                x = (frandom() * 2.0 - 1.0) * R;
                y = (frandom() * 2.0 - 1.0) * R;
                z = (frandom() * 2.0 - 1.0) * R;
            } while (x * x + y * y + z * z > (double)R * R);

            int best = 0;
            double bestd = dist2(p[0], x, y, z);

            for (int i = 1; i < N; i++) {
                double d = dist2(p[i], x, y, z);

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
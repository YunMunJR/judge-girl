#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;

    while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        double d = sqrt(b * b - 4 * a * c);

        double x1 = (-b - d) / (2 * a);
        double x2 = (-b + d) / (2 * a);

        printf("%.20f %.20f\n", x1, x2);
    }

    return 0;
}
#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    long long a, b;

    while (scanf("%lld %lld", &a, &b) == 2) {
        long long g = gcd(a, b);
        printf("%lld / %lld\n", a / g, b / g);
    }

    return 0;
}
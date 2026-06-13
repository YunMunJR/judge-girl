#include <stdio.h>

int main() {
    int x;
    long long sum = 0;

    while (scanf("%d", &x) == 1)
        sum += x;

    printf("%lld\n", sum);
    return 0;
}
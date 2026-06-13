#include <stdio.h>

typedef unsigned long long ull;

ull addmod(ull x, ull y, ull mod) {
    if (x >= mod - y)
        return x - (mod - y);
    else
        return x + y;
}

ull mulmod(ull a, ull b, ull mod) {
    ull ans = 0;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            ans = addmod(ans, a, mod);
        a = addmod(a, a, mod);
        b >>= 1;
    }
    return ans;
}

int main() {
    ull a, b, n;
    while (scanf("%llu %llu %llu", &a, &b, &n) == 3) {
        printf("%llu\n", mulmod(a, b, n));
    }
    return 0;
}
#include <stdio.h>

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        int x, prev;
        int cnt = 1;
        scanf("%d", &prev);
        for (int i = 1; i < N; i++) {
            scanf("%d", &x);
            if (x != prev)
                cnt++;
            prev = x;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
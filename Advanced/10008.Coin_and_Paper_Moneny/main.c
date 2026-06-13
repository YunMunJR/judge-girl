#include <stdio.h>

int main() {
    int money[] = {1000, 500, 100, 50, 10, 5, 1};
    int N;

    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < 7; i++) {
            int cnt = N / money[i];
            N %= money[i];

            if (i) printf(" ");
            printf("%d", cnt);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    char word[205][55];
    for (int i = 0; i < N; i++) {
        scanf("%s", word[i]);
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        char s[55];
        scanf("%s", s);
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (strstr(word[i], s) != NULL) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
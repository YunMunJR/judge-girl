#include <stdio.h>

int main() {
    char s[100005];
    int n;

    scanf("%s", s);
    scanf("%d", &n);
    while (n--) {
        char u, v;
        scanf(" %c %c", &u, &v);
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == v) {
                s[i] = u;
            }
        }
    }

    printf("%s\n", s);
    return 0;
}
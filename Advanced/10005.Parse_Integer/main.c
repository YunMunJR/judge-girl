#include <stdio.h>
#include <ctype.h>

int main() {
    char s[1024];
    while (scanf("%s", s) == 1) {
        int i = 0;
        while (s[i] != '\0') {
            int sign = 1;
            if (s[i] == '-' && isdigit(s[i + 1])) {
                sign = -1;
                i++;
            }
            if (isdigit(s[i])) {
                long long num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                printf("%lld\n", sign * num);
            } else {
                i++;
            }
        }
    }

    return 0;
}
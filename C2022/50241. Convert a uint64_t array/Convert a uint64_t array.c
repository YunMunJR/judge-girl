#include <stdio.h>
#include <stdint.h>
int main(){
    static uint64_t num,temp; int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%llu", &num);
        for (int j = 0; j < 12; j++) {
            temp = num % 32;
            printf("%c", 'a' + temp);
            num /= 32;
        }
    }
    return 0;
}
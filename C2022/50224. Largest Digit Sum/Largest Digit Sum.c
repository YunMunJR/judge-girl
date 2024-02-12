#include <stdio.h>
typedef struct n{
    int prev;
    int curr;
}n;
int main(){
    int digit,d=0;
    n  sum = { 0,0 }, num = { 0,0 },number={0,0};
    while (scanf("%d", &digit) != EOF){
        d = digit;
        sum.curr = 0;
        num.curr = 0;
        number.curr = digit;
        while (d != 0){
            sum.curr += d % 10;
            num.curr++;
            d /= 10;
        }
        if (sum.curr > sum.prev){
            sum.prev = sum.curr;
            number.prev = number.curr;
            num.prev = num.curr;
        }else if (sum.curr == sum.prev){
            if (num.curr < num.prev){
                sum.prev = sum.curr;
                number.prev = number.curr;
                num.prev = num.curr;
            }else if (num.curr == num.prev){
                if (number.curr > number.prev){
                    sum.prev = sum.curr;
                    number.prev = number.curr;
                    num.prev = num.curr;
                }
            }
        }
    }
    if (number.prev == 0){
        number.prev = num.curr;
    }       
    printf("%d", number.prev);
    return 0;
}
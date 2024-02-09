#include <stdio.h>
int solve(long long digit){
    int ans = 0;
    while (digit > 0){
        if (digit % 2 == 1){
            ans++; 
            digit = (digit - 1) / 2;
        }else{
            digit /= 2;
        }
    }
    return ans;
}
int main(){
    long long digit;
    while (scanf("%lld", &digit) != EOF){
        printf("%d\n", solve(digit));
    }
    return 0;
}
#include <stdio.h>
int solve(int digit){
    int ans=0 , max = 0;
    while (digit > 0){
        if (digit % 2 != 0){
            ans++; 
            digit = (digit - 1) / 2;
        }else{
             ans = 0; 
             digit /= 2;
        }
        max = (max < ans) ? ans : max;
    }
    return max;
}
int main(){
    int digit;
    while (scanf("%d", &digit) != EOF){
        printf("%d\n", solve(digit));
    }
    return 0;
}
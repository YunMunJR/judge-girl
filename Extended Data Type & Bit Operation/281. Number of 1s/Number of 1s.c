#include <stdio.h>
int solve(int digit){
    int ans=0;
    while (digit > 0){
        if (digit % 2 == 1){
            ans++; digit = (digit - 1) / 2;
        }else{
            digit /= 2; 
        }
    }
    return ans;
}
int main(){
    int digit;
    while (scanf("%d", &digit) != EOF){
        printf("%d\n",solve(digit));
    }
    return 0;
}
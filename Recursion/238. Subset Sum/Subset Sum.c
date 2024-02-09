#include <stdio.h>
int subset_sum(int arr[], int sum,int n,int init_sum)
{
    if (n < 0){
        return((sum == init_sum) ? 1 : 0);
    }else{
        if (init_sum == sum){
            return 1;
        }      
    }
    return (subset_sum(arr, sum, n - 1, init_sum + arr[n]) + subset_sum(arr, sum, n - 1, init_sum));
}
int main(){
    int n,a[15]={0},digit;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }      
    while (scanf("%d", &digit) != EOF){
        int ans = subset_sum(a, digit, n-1, 0);
        printf("%d\n", ans);
    }
    return 0;
}
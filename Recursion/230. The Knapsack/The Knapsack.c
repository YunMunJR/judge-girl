#include <stdio.h>
int max(int a, int b) {
    return(a > b) ? a : b;
};
typedef struct Object {
    int wei, val;
}object;
int knapsack(object arr[], int n, int W) {
    if (n >= 0){
        if (W < arr[n].wei){
            return knapsack(arr, n - 1, W);
        }       
    }
    else{
        return 0;
    }    
    return max(knapsack(arr, n - 1, W), (knapsack(arr, n - 1, W - arr[n].wei) + arr[n].val));
};
int main(){
    int n, W;
    scanf("%d%d", &n, &W);
    object o[500];
    for (int i = 0; i < n; i++)
        scanf("%d%d", &o[i].wei, &o[i].val);
    int maxval = knapsack(o, n, W);
    printf("%d", maxval);
    return 0;
}
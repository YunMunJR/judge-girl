#include <stdio.h>
int main(){
    int i, j, k; 
    static int cup_cap[20000],cup_water[20000];
    scanf("%d", &k);
    for (int ii = 0; ii < k; ii++){
        scanf("%d", &cup_cap[ii]);
    }
    for (int ii = 0; ii < k; ii++){
        scanf("%d", &cup_water[ii]);
    }
    while (scanf("%d%d", &i, &j) != EOF) {
        if (i == k || j == k) {
            if (i == k){
                cup_water[j] = cup_cap[j];
            }else{
                cup_water[i] = 0;
            }
        }else {
            if (cup_water[i] + cup_water[j] >= cup_cap[j]){  
                cup_water[i] -= (cup_cap[j] - cup_water[j]);
                cup_water[j] = cup_cap[j]; 
            }else{ 
                cup_water[j] += cup_water[i]; 
                cup_water[i] = 0; 
            }
        }
    }
    for (int ii = 0; ii < k; ii++){
        printf("%d ", cup_water[ii]);
    }
    return 0;
}
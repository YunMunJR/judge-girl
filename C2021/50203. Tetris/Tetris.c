#define MAXSIZE 100000
#include <stdio.h>
int max(int a, int b) {
    return(a > b) ? a : b;
}
int main(){
    static int row[MAXSIZE] = { 0 }; int n, a, b;
    scanf("%d", &n);
    while (scanf("%d%d", &a, &b) != EOF) {
        if (b == 0) {
            if (row[a] > row[a + 1]&& row[a] > row[a + 2]){
                row[a]++; 
                row[a + 1] = row[a]; 
                row[a + 2] = row[a] - 1;
            }else{
                row[a] = max(row[a + 1], row[a + 2]) + 2; 
                row[a + 1] = row[a]; 
                row[a + 2] = row[a] - 1;
            }
        }else if (b == 1) {
            if (row[a + 2] > row[a + 1]&& row[a + 2] > row[a]) {
                row[a + 2]++; 
                row[a + 1] = row[a + 2]; 
                row[a] = row[a + 2] - 1;
            }else {
                row[a + 2] = max(row[a + 1], row[a]) + 2; 
                row[a + 1] = row[a + 2]; 
                row[a] = row[a + 2] - 1;
            }
        }else if (b == 2) {
            row[a] = max(row[a], max(row[a + 1], row[a + 2])) + 1; 
            row[a + 1] = row[a] + 1; 
            row[a + 2] = row[a];
        }else {
            if (max(row[a], row[a + 2]) > row[a + 1]) {
                row[a] = max(row[a], row[a + 2]) + 1; 
                row[a + 1] = row[a]; 
                row[a + 2] = row[a];
            }else {
                row[a + 1] += 2; 
                row[a] = row[a + 2] = row[a + 1]; 
                row[a] = row[a + 1];
            }
        }
    }
    for (int i = 0; i < n; i++){
        printf("%d ", row[i]);
    }
    return 0;
}
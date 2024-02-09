#include <stdio.h>
#include <stdbool.h>
int find_composition(int material[3][3],int a_unit,int b_unit,int c_unit ){
    if (a_unit < 0 || b_unit < 0 || c_unit < 0){
        return 0;
    }else{
        if (a_unit == 0 && b_unit == 0 && c_unit == 0){
            return 1;
        }        
    }
    return find_composition(material, a_unit - material[0][0], b_unit - material[0][1], c_unit - material[0][2])||
        find_composition(material, a_unit - material[1][0], b_unit - material[1][1], c_unit - material[1][2])||
        find_composition(material, a_unit - material[2][0], b_unit - material[2][1], c_unit - material[2][2]);
}
void scan_data(int material[3][3],int arr[][3], int n, int curr_times,int TF[]){
    if (curr_times < n){
        scanf("%d%d%d", &arr[curr_times][0], &arr[curr_times][1], &arr[curr_times][2]);
        TF[curr_times] = find_composition(material, arr[curr_times][0], arr[curr_times][1], arr[curr_times][2]);
        scan_data(material,arr, n, curr_times + 1,TF);
    }
}
void print_data(int TF[],int n,int curr_times){
    if (curr_times<n){
        printf((TF[curr_times] == 1) ? "yes\n" : "no\n");
        print_data(TF, n, curr_times + 1);
    }
}
int main(void)
{
    int material[3][3] = { 0 }, n, a[100][3] = { 0 }; 
    int TorF[100]={0};
    scanf("%d%d%d", &material[0][0],&material[0][1],&material[0][2]);
    scanf("%d%d%d", &material[1][0], &material[1][1], &material[1][2]);
    scanf("%d%d%d", &material[2][0], &material[2][1], &material[2][2]);
    scanf("%d", &n);
    scan_data(material,a, n, 0,TorF);
    print_data(TorF, n, 0);
    return 0;
}
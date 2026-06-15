#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n,i,j,temp;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=n-1;i>=0;i--){
        if(i!=0){
            printf("%d ",a[i]);
        }else{
            printf("%d",a[i]);
        } 
    } 
    return 0;
}
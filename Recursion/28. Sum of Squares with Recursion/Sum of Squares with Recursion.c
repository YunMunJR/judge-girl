#include <stdio.h>
int solve(int i,int n){
    if(i>n){
        return 0;
    }
    return (i*i)+solve(i+1,n);
}
int main(){
    int n;
    scanf("%d",&n);
    int ans=solve(1,n);
    printf("%d",ans);
    return 0;
}
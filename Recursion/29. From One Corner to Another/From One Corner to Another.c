#include <stdio.h>
int solve(int map[12][12],int r,int c){
    if(r==0||c==0){
        return 1;
    }
    return solve(map,r-1,c)+solve(map,r,c-1);
}
int main(int argc, char *argv[]) {
    int r,c;
    int map[12][12]={0};
    scanf("%d%d",&r,&c);
    int var=solve(map,r-1,c-1);
    printf("%d",var);
    return 0;
}
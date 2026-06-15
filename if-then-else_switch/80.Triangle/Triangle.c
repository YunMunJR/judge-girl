#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
    int i,j,n;
    scanf("%d",&n);
    int a[n][9];
    for(i=0;i<n;i++){
        for(j=0;j<6;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        a[i][6]=pow((a[i][2]-a[i][0]),2)+pow((a[i][3]-a[i][1]),2);
        a[i][7]=pow((a[i][4]-a[i][2]),2)+pow((a[i][5]-a[i][3]),2);
        a[i][8]=pow((a[i][0]-a[i][4]),2)+pow((a[i][1]-a[i][5]),2);
    }
    for(i=0;i<n;i++){
        if(a[i][6]==a[i][7]||a[i][7]==a[i][8]||a[i][8]==a[i][6]){
            fputs("isosceles\n",stdout); 
        }else{
            if(a[i][6]+a[i][7]>a[i][8]&&a[i][6]+a[i][8]>a[i][7]&&a[i][7]+a[i][8]>a[i][6]){
                fputs("acute\n",stdout);
            }else if(a[i][6]+a[i][7]==a[i][8]||a[i][6]+a[i][8]==a[i][7]||a[i][7]+a[i][8]==a[i][6]){
                fputs("right\n",stdout);
            }else{
                fputs("obtuse\n",stdout);
            }
        }
    }
    return 0;
}
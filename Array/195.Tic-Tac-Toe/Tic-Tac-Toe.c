#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int i,j,a[3][3],num=1,n,i2,j2,linew=0,lineb=0,t;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            a[i][j]=0;
        }    
    }
    scanf("%d",&n);
    int b[n][2];
    for(i=0;i<n;i++){
        for(j=0;j<2;j++){
            scanf("%d",&b[i][j]);
        } 
    }
    for(t=0;t<n;t++){
        if(lineb!=0){
            fputs("Black wins.\n",stdout);
            break;
        }else if (linew!=0){
            fputs("White wins.\n",stdout);
            break;
        }
        i2=b[t][0];
        j2=b[t][1];
        if(a[2-j2][i2]==0){
            if(num%2!=0){
                a[2-j2][i2]=2;
                num++;
            }else{
                a[2-j2][i2]=1;
                num++;
            }        
            for(i=0;i<3;i++){
                if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]&&a[i][1]!=0){
                    if(a[i][1]==2){
                        lineb++;
                    }else{
                        linew++;
                    }
                }
            }
            for(i=0;i<3;i++){
                if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]&&a[1][i]!=0){
                    if(a[1][i]==2){
                        lineb++;
                    }else{
                        linew++;
                    }
                }
            }
            if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[1][1]!=0){
                if(a[1][1]==2){
                    lineb++;
                }else{
                    linew++;
                }
            }
            if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[1][1]!=0){
                if(a[1][1]==2){
                    lineb++;
                }else{
                    linew++;
                } 
            }    
        }
    }
    if(lineb==0&&linew==0){
        fputs("There is a draw.",stdout);
    }
    return 0;
}
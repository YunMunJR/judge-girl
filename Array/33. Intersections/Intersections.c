#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int i,j,n,intersection=0,Tjunction=0,Tturn=0,deadend=0,num=0;
    scanf("%d",&n);
    int a[n+2][n+2];
    for(i=0;i<n+2;i++){
        for(j=0;j<n+2;j++){
            a[i][j]=0;
        }   
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<n+1;i++){    
        for(j=1;j<n+1;j++){
            num=0;
            if(a[i][j]==1){
                if(a[i][j+1]==1){
                    num++;
                }
                if(a[i][j-1]==1){
                    num++;
                }
                if(a[i+1][j]==1){
                    num++;
                }
                if(a[i-1][j]==1){
                    num++;
                }
            }
            if(num!=2){
                switch (num){
                    case 1:
                        deadend++;
                        break;
                    case 3:
                        Tjunction++;
                        break;
                    case 4:
                        intersection++;
                        break; 
                    default:
                        break;
                }
            }else{
                if(!((a[i][j+1]==1&&a[i][j-1]==1)||(a[i+1][j]==1&&a[i-1][j]==1))){
                    Tturn++;
                }else{
                    Tturn+=0;
                }  
            }
        }
    }
    printf("%d\n",intersection);
    printf("%d\n",Tjunction);
    printf("%d\n",Tturn);
    printf("%d\n",deadend);
    return 0;
}
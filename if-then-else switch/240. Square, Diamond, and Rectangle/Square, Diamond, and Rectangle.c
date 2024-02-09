#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
    int n,i,j,k,c[1][2],b[3],numplus=0,numsubstract=0,d[4][2],dot[4];
    double length[4];
    scanf("%d",&n);
    int a[n][14];
    for(i=0;i<n;i++){
        for(j=0;j<8;j++){
            scanf("%d",&a[i][j]);
        }    
    }     
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            a[i][2*j+8]=a[i][2*j]-a[i][6];
            a[i][2*j+9]=a[i][2*j+1]-a[i][7];
        }
        b[0]=a[i][8]*a[i][11]-a[i][9]*a[i][10];
        b[1]=a[i][10]*a[i][13]-a[i][11]*a[i][12];
        b[2]=a[i][12]*a[i][9]-a[i][13]*a[i][8];
        for(j=0;j<3;j++){
            if(b[j]>0){
                numplus++;
            }else{
                numsubstract++;
            } 
        }
        if(numplus%2!=0){
            for(j=0;j<3;j++){
                if(b[j]>0){    
                    switch (j){
                        case 0:
                            for(j=0;j<2;j++){
                                c[0][j]=a[i][6+j];
                            }  
                            for(j=5;j>1;j--){
                                a[i][j+2]=a[i][j];
                            }
                            a[i][2]=c[0][0];
                            a[i][3]=c[0][1];
                            break;
                        case 1:
                            for(j=0;j<2;j++){
                                c[0][j]=a[i][6+j];
                            }
                            for(j=5;j>3;j--){
                                a[i][j+2]=a[i][j];
                            }
                            a[i][4]=c[0][0];
                            a[i][5]=c[0][1];                  
                            break;  
                        default:
                            break;
                    }
                }
            }
        }else{
            for(j=0;j<3;j++){
                if(b[j]<0){
                    switch (j){
                        case 0:
                            for(j=0;j<2;j++){
                                c[0][j]=a[i][6+j];
                            }
                            for(j=5;j>1;j--){
                                a[i][j+2]=a[i][j];
                            }  
                            a[i][2]=c[0][0];
                            a[i][3]=c[0][1];
                            break;
                        case 1:
                            for(j=0;j<2;j++){
                                c[0][j]=a[i][6+j];
                            }
                            for(j=5;j>3;j--){
                                a[i][j+2]=a[i][j];
                            }
                            a[i][4]=c[0][0];
                            a[i][5]=c[0][1];
                            break;    
                        default:
                            break;
                    }
                }
            }
        }       
        for(k=0;k<3;k++){
            for(j=0;j<2;j++){
                d[k][j]=a[i][2*k+2+j]-a[i][2*k+j];  
            }
        }
        d[3][0]=a[i][0]-a[i][6];
        d[3][1]=a[i][1]-a[i][7];
        for(j=0;j<3;j++){
            length[j]=sqrt(pow((a[i][2*j]-a[i][2*j+2]),2)+pow((a[i][2*j+1]-a[i][2*j+3]),2));
            length[3]=sqrt(pow((a[i][6]-a[i][0]),2)+pow((a[i][7]-a[i][1]),2));
        }
        for(k=0;k<3;k++){
            dot[k]=d[k][0]*d[k+1][0]+d[k][1]*d[k+1][1];
            dot[3]=d[3][0]*d[0][0]+d[3][1]*d[0][1];
        }
        if(length[0]==length[1]&&length[1]==length[2]&&length[2]==length[3]&&length[3]==length[0]){
            if(dot[0]==0&&dot[1]==0&&dot[2]==0&&dot[3]==0){
                fputs("square\n",stdout);
            }else{
                fputs("diamond\n",stdout);
            }
        }else{
            if(dot[0]==0&&dot[1]==0&&dot[2]==0&&dot[3]==0){
                fputs("rectangle\n",stdout);
            }else{
                fputs("other\n",stdout); 
            }
        }
        numplus=0;
        numsubstract=0;
    }    
    return 0;
}
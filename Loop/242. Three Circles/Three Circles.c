#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
    int n,i,j,p,q,poi[2000][2]={100000000},t=0,m=1,x=0,g;
    scanf("%d",&n);
    int a[n*3][3],xmin=0,xmax=0,ymin=0,ymax=0,nump=0,num=0,k;
    for(i=0;i<3*n;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }      
    }
    for(i=0;i<n;i++){    
        for(j=0;j<3;j++){
            xmin=a[3*i+j][0]-a[3*i+j][2];    
            xmax=a[3*i+j][0]+a[3*i+j][2];
            ymin=a[3*i+j][1]-a[3*i+j][2];
            ymax=a[3*i+j][1]+a[3*i+j][2];
            for(p=ymax;p>=ymin;p--){
                for(q=xmin;q<=xmax;q++){
                    for(t=0;t<m-1;t++){
                        if(p==poi[t][1]&&q==poi[t][0]){
                            x++;
                        }
                    }
                    if(x==0){
                        if(pow(q-a[3*i+0][0],2)+pow(p-a[3*i+0][1],2)<=pow(a[3*i+0][2],2)){
                            num++;
                        }    
                        if(pow(q-a[3*i+1][0],2)+pow(p-a[3*i+1][1],2)<=pow(a[3*i+1][2],2)){
                            num++;
                        }
                        if(pow(q-a[3*i+2][0],2)+pow(p-a[3*i+2][1],2)<=pow(a[3*i+2][2],2)){
                            num++;
                        }  
                        poi[m-1][1]=p;
                        poi[m-1][0]=q;
                        m++;
                    }
                    if(num%2!=0){
                        nump++;
                    }      
                    x=0;
                    num=0;
                }        
            }    
        }
        for(g=0;g<m;g++){
            for(j=0;j<2;j++){
                poi[g][j]=100000000;
            } 
        }
        printf("%d\n",nump);
        nump=0;
        m=1;     
    }        
    return 0;
}
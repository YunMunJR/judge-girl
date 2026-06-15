#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
    int a[50]={0},i=0,j,number,b[6],sum=0,n=0,m=0,k;
    while(scanf("%d",&number)!=EOF){
        a[i]=number;
        i++;
    } 
    i=6;
    while(a[i]!=0){
        for(j=0;j<6;j++){
            b[j]=a[i]-a[j];
        }
        for(j=3;j<6;j++){ 
            n=0;
            if(b[j]!=0) {
                while(m==0){
                    m=b[j]%10;
                    b[j]=b[j]/10;
                    n++;    
                }
                m=0;
                n-=1;
                switch(n){
                    case 3:
                        sum+=200;
                        break;
                    case 4:
                        sum+=1000;
                        break;
                    case 5:
                        sum+=4000;
                        break;
                    case 6:
                        sum+=10000;
                        break;
                    case 7:
                        sum+=40000;
                        break;
                    default:
                        sum=sum;     
                }
            }else{
                sum+=200000; 
            }
        }
        for(j=0;j<3;j++){
            if(b[j]==0){
                sum+=2000000;
            }
        }
        i++;     
    }
    printf("%d\n",sum);
    return 0;
}
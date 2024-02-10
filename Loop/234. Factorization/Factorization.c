#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
    int a[3],b[3],i,j,num=0,temp,x3=0,x2=0,x1=0,x0=0,don[3]={0};
    long long int pan=0;
    for(i=0;i<3;i++){
        scanf("%d",&a[i]);
    }
    i=abs(a[2]);
    while(i>=-(abs(a[2]))&&num<1){
        x3=pow(i,3);
        x2=a[0]*pow(i,2);
        x1=a[1]*i; 
        x0=a[2];
        if((x3+x2+x1+x0)==0){
            b[num]=i;
            num++;
        }
        i--;
    }
    don[0]=1;
    don[1]=a[0]+b[0];
    don[2]=a[1]+don[1]*b[0];
    pan=pow(don[1],2)-4*don[0]*don[2];
    if(pan>=0){
        b[1]=(-don[1]-sqrt(pan))/2;
        b[2]=(-don[1]+sqrt(pan))/2;
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                if(b[j]<b[j+1]){
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;    
                }    
            }
        }
        printf("%d %d %d",-b[0],-b[1],-b[2]);        
    }else{
        printf("%d",b[0]);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n,i,j,k=0,m,n1,m1,A=0,B=0,a[4],b[4];
    scanf("%d %d",&m,&n);
    while(m>0&&n>0){
        m1=m%10;
        n1=n%10;
        a[k]=m1;
        b[k]=n1;
        if(n1==m1){
            A++;
        }    
        m=(m-m1)/10;
        n=(n-n1)/10;      
        k++;
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(a[j]==b[i]){
                B++; 
            } 
        }
    }
    B-=A;
    printf("%dA%dB",A,B);
    return 0;
}
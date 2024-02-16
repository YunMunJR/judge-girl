#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n,k,L,num_int1,num_int2,i,j,t,i2,num,L_;
    t=0,i2=0;
    static int a[200];
    div_t output;    
    scanf("%d",&k);
    scanf("%d",&L);
    L_=L;
    while(scanf("%d",&n)!=EOF){
        a[t]=n;
        t++;
    }    
    for(i=0;i<t;i++){
        output=div(a[i],k);
        if(output.rem!=0){
            num=a[i];
            while(num!=0){
                num/=10;
                i2++;
            }    
            if(i2*output.rem<=L){
                if(output.rem*i2<=L_){
                    for(j=0;j<output.rem;j++){
                        printf("%d",a[i]); 
                    }       
                L_-=output.rem*i2;
                i2=0;    
                }else{
                    putchar('\n');
                    L_=L;
                    for(j=0;j<output.rem;j++){
                        printf("%d",a[i]);
                    }
                    L_-=output.rem*i2;    
                    i2=0;        
                }
            }else{
                i2=0;
                continue;
            }
        }
    }
    return 0;
}
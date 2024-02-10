#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int digit,gcd,lcm=1,i,j;
    while(scanf("%d",&digit)!=EOF){
        if(lcm>digit){
            i=lcm;
            j=digit;
            while(j!=0&&i!=0){
                if(j==0||i==0){
                    break;
                }
                i%=j;
                if(j==0||i==0){
                    break;
                }
                j%=i;
            }
            if(i!=0){
                lcm*=digit/i;
            }else{
                lcm*=digit/j;
            }
        }else{
            i=lcm;
            j=digit;
            while(j!=0&&i!=0){   
                if(j==0||i==0){
                    break;
                }
                j%=i;
                if(j==0||i==0){
                    break;
                }  
                i%=j;    
            }
            if(i!=0){
                lcm*=digit/i;
            }else{
                lcm*=digit/j;
            }
        }
    }
    printf("%d",lcm);
    return 0;
}
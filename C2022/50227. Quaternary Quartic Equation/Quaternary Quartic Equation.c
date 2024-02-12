#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int max(int a,int b){
    int max=(a>b)?a:b;
    return max; 
}
int min(int a,int b){
    int min=(a<b)?a:b;
    return min;
}
int main(int argc, char *argv[]) {
    int a,b,c,d,s1,s2,s3,s4;
    scanf("%d%d%d%d",&s1,&s2,&s3,&s4);
    b=3;c=2;d=1,a=s1-d-b-c;
    int n=min(sqrt(s2),min(pow(s3,0.333333),pow(s4,0.25)));
    if(a+b+c+d<10||a*a+b*b+c*c+d*d<30||a*a*a+b*b*b+c*c*c+d*d*d<100||a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d<354){
        fputs("-1",stdout);
    } 
    for(a=n+1;a>=4;a--){
        for(b=3;b<=a-1;b++){
            for(c=2;c<=b-1;c++){
                for(d=1;d<=c-1;d++){
                    if(a+b+c+d==s1&&a*a+b*b+c*c+d*d==s2&&a*a*a+b*b*b+c*c*c+d*d*d==s3&&a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d==s4){
                        break;
                    }else{
                        continue;
                    }
                }
                if(a+b+c+d==s1&&a*a+b*b+c*c+d*d==s2&&a*a*a+b*b*b+c*c*c+d*d*d==s3&&a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d==s4){
                    break;
                }else{
                    continue;
                }
            }
            if(a+b+c+d==s1&&a*a+b*b+c*c+d*d==s2&&a*a*a+b*b*b+c*c*c+d*d*d==s3&&a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d==s4){
                break;
            }else{
                continue;
            }     
        }
        if(a+b+c+d==s1&&a*a+b*b+c*c+d*d==s2&&a*a*a+b*b*b+c*c*c+d*d*d==s3&&a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d==s4){
            printf("%d\n",a);
            printf("%d\n",max(b,max(c,d)));
            printf("%d\n",s1-a-max(b,max(c,d))-min(b,min(c,d)));
            printf("%d\n",min(b,min(c,d)));
            break;
        }else{
            if(a!=4){
                continue;
            }else{
                fputs("-1",stdout);
            }   
        }
    }
    return 0;
}
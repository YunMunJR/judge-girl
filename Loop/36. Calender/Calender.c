#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int a[3],i,j,daycorrect=0,yearcorrect=0,n=0;
    for(i=0;i<3;i++){
        scanf("%d",&a[i]);
    }
    if(a[1]<1||a[1]>12){
        fputs("invalid\n",stdout);
    }else{
        switch(a[1]){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if(a[2]<0||a[2]>7){
                    fputs("invalid\n",stdout);
                }else{
                    fputs(" Su Mo Tu We Th Fr Sa\n",stdout) ;
                    fputs("=====================\n",stdout);
                    for(i=0;i<a[2];i++){
                        fputs("   ",stdout);
                    }
                    n=a[2];
                    for(i=1;i<32;i++){ 
                        if(i!=31){
                            if(n==6){
                                printf("%3d\n",i);
                                n=0;
                            }else{
                                printf("%3d",i);
                                n++;
                            }
                        }else{
                            printf("%3d\n",i);
                        }
                         
                    }
                    fputs("=====================\n",stdout);
                }    
            break;
        case 4: case 6: case 9: case 11:
            if(a[2]<0||a[2]>7){
                fputs("invalid\n",stdout);
            }else{
                fputs(" Su Mo Tu We Th Fr Sa\n",stdout) ;
                fputs("=====================\n",stdout);
                for(i=0;i<a[2];i++){
                    fputs("   ",stdout);
                }
                n=a[2];
                for(i=1;i<31;i++)  { 
                    if(i!=30){
                        if(n==6){
                            printf("%3d\n",i);
                            n=0;
                        }else{
                            printf("%3d",i);
                            n++;
                        }
                    }else{
                        printf("%3d\n",i);
                    }
                }
                fputs("=====================\n",stdout);
            }
            break;    
            case 2:
                if(a[2]<0||a[2]>7){
                    fputs("invalid\n",stdout);
                }else{
                    if((a[0]%4==0&&a[0]%100!=0)||a[0]%400==0){
                        fputs(" Su Mo Tu We Th Fr Sa\n",stdout) ;
                        fputs("=====================\n",stdout);
                        for(i=0;i<a[2];i++){
                            fputs("   ",stdout);
                        }
                        n=a[2];
                        for(i=1;i<30;i++){ 
                            if(i!=29){
                                if(n==6){
                                    printf("%3d\n",i);
                                    n=0;
                                }else{
                                    printf("%3d",i);
                                    n++;
                                }
                            }else{
                                printf("%3d\n",i);
                            }
                        }
                        fputs("=====================\n",stdout);
                    }else{
                        fputs(" Su Mo Tu We Th Fr Sa\n",stdout) ;
                        fputs("=====================\n",stdout);
                        for(i=0;i<a[2];i++){
                            fputs("   ",stdout);
                        }
                        n=a[2];
                        for(i=1;i<29;i++){ 
                            if(i!=28){
                                if(n==6){
                                    printf("%3d\n",i);
                                    n=0;
                                }else{
                                    printf("%3d",i);
                                    n++;
                                }
                            }else{
                                printf("%3d\n",i);
                            }
                        }
                        fputs("=====================\n",stdout);
                    }
                }
                break;
        }
 
    }
    return 0;
}
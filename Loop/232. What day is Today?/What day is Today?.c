#include <stdio.h>
#include <stdlib.h>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int main(int argc, char *argv[]) {
    int year,day,n,i,j,m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},sum=0,yearcorrect=1,daycorrect=1,day1;
    scanf("%d %d",&year,&day);
    day1=day;
    scanf("%d",&n);
    int a[n][2];
    for(i=0;i<n;i++){
        for(j=0;j<2;j++){
            scanf("%d",&a[i][j]);
        } 
    }     
    for(i=0;i<n;i++){
        if(a[i][0]>0&&a[i][0]<13){
            yearcorrect=1;
            daycorrect=1;
            if((year%4==0&&year%100!=0)||year%400==0){  
                m[2]=29;
                switch (a[i][0]){
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        if(a[i][1]<1||a[i][1]>31){
                            fputs("-2\n",stdout);
                            daycorrect=0;
                            break;
                        }
                    case 4: case 6: case 9: case 11:
                        if(a[i][1]<1||a[i][1]>30){
                            fputs("-2\n",stdout);
                            daycorrect=0;
                            break;
                        }
                    case 2:
                        if(a[i][1]<1||a[i][1]>29){
                            fputs("-2\n",stdout);
                            daycorrect=0;
                            break;
                        }
                }
            }else{
                switch (a[i][0]){
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        if(a[i][1]<1||a[i][1]>31){
                            fputs("-2\n",stdout);
                            daycorrect=0;
                            break;
                        }
                    case 4: case 6: case 9: case 11:
                        if(a[i][1]<1||a[i][1]>30){
                            fputs("-2\n",stdout);
                            daycorrect=0;
                            break;
                        }
                    case 2:
                        if(a[i][1]<1||a[i][1]>28){
                            fputs("-2\n",stdout);
                            daycorrect=0;
                            break;
                        }
                }
            } 
            if(yearcorrect==1&&daycorrect==1){
                for(j=0;j<a[i][0];j++){
                    sum+=m[j];
                }
                sum+=a[i][1];
                sum-=1;
                day1+=sum%7;
                if(day1>=7){
                    day1-=7;
                }   
                sum=0;     
                printf("%d\n",day1);
                day1=day;
                daycorrect=1;
                yearcorrect=1;    
            }
        }
        else{    
            fputs("-1\n",stdout);
            yearcorrect=0;
        } 
    }
    return 0;
}
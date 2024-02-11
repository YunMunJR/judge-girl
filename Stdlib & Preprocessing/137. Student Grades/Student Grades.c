#include <stdio.h>
#include <string.h>
typedef struct{
    char s[3];
    int high;
    int low;
    int grade;
    float gpa;
}rank;
int main(){
    rank r[10];
    strcpy(r[0].s,"A+"); r[0].high=100;r[0].low=90;r[0].grade=95;r[0].gpa=4.3;
    strcpy(r[1].s,"A"); r[1].high=89;r[1].low=85;r[1].grade=87;r[1].gpa=4.0;
    strcpy(r[2].s,"A-"); r[2].high=84;r[2].low=80;r[2].grade=82;r[2].gpa=3.7;
    strcpy(r[3].s,"B+"); r[3].high=79;r[3].low=77;r[3].grade=78;r[3].gpa=3.3;
    strcpy(r[4].s,"B"); r[4].high=76;r[4].low=73;r[4].grade=75;r[4].gpa=3.0;
    strcpy(r[5].s,"B-"); r[5].high=72;r[5].low=70;r[5].grade=70;r[5].gpa=2.7;
    strcpy(r[6].s,"C+"); r[6].high=69;r[6].low=67;r[6].grade=68;r[6].gpa=2.3;
    strcpy(r[7].s,"C"); r[7].high=67;r[7].low=63;r[7].grade=65;r[7].gpa=2.0;
    strcpy(r[8].s,"C-"); r[8].high=62;r[8].low=60;r[8].grade=60;r[8].gpa=1.7;
    strcpy(r[9].s,"F"); r[9].high=59;r[9].low=0;r[9].grade=50;r[9].gpa=0.0;
    int g,avr,sum=0;
    float gpatotal=0.0,c=0.0;
    while(scanf("%d",&g)!=EOF){   
#ifdef HUNDRED
        sum+=g;
        printf("%d ",g);
#endif
#ifdef APLUS
        for(int i=0;i<10;i++){
            if(r[i].high>=g&&r[i].low<=g){
                printf("%s ",r[i].s);
                sum+=r[i].grade;
                gpatotal+=r[i].gpa;
                break;
            }
        }
#endif
        c+=1.0;
    }
    
#ifdef HUNDRED
        printf("%.1f",(float)sum/c);
#endif
#ifdef APLUS
        printf("%.1f %.1f",(float)gpatotal/c,(float)sum/c);
#endif
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
typedef struct date{
    int year;
    int month;
    int day;
}date;
int cmp(const void*a,const void*b){
    date *ptr1=a;
    date *ptr2=b;
    if(ptr1->year-ptr2->year){
        return ptr1->year-ptr2->year;
    }else{
        if(ptr1->month-ptr2->month){
            return ptr1->month-ptr2->month;
        }else{
            if(ptr1->day-ptr2->day){
                return ptr1->day-ptr2->day;
            }else{
                return 0;
            }
        }
    }
    return 0;
}
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
int main(int argc, char *argv[]) {
    int n,num=0;
    int x;
    static date data[1000000];
    scanf("%d",&n);
    while (ReadInt(&x)) { 
        if(num%3==0){
            data[num/3].year=x;
        }else if(num%3==1){
            data[num/3].month=x;
        }else{
            data[num/3].day=x;
        } 
        num++;
    }
    qsort(data,n,sizeof(date),cmp);
    for(int i=0;i<n;i++){
        printf("%d %d %d\n",data[i].year,data[i].month,data[i].day);
    }
    return 0;
}
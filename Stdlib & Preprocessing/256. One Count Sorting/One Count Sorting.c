 #include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
typedef struct {
    long long num;
    int onenum;
}data;
int findmaxidx(data num[], int count) {
    int idx = 0;
    for (int i = 1; i < count; i++) {
        if (num[i].onenum > num[idx].onenum)idx = i;
        else if (num[i].onenum == num[idx].onenum) {
            if (num[i].num > num[idx].num)idx = i;
        }
    }
    return idx;
}
int onenum(long long num) {
    int re = 0; long long n = num; 
    while (n >= 1) {    
        if (n % 2)re++;
        n /= 2;
    }
    return re;
}
int cmp(const void*a,const void*b){
    data*c=(data*)a;
    data*d=(data*)b;
    if(c->onenum!=d->onenum){
        if(c->onenum>d->onenum)return 1;
        else return -1;
    }else{
        if(c->num>d->num)return 1;
        else return -1;
    }
}
int main() {
    data num[1000], temp;
    long long n;
    int count = 0, maxidx;
    while (scanf("%lld", &n) != EOF) {
        num[count].num = n; count++;
    }
    for (int i = 0; i < count; i++) {
        num[i].onenum = onenum(num[i].num);   
    }  
    qsort(num,count,sizeof(data),cmp);
    for (int i = 0; i < count; i++){
        printf("%lld\n", num[i].num);
    }
}
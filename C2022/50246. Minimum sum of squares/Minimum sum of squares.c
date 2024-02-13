#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
typedef struct{
    uint64_t a[20];
    uint64_t sub[10];
    uint64_t count;
    uint64_t mini;
}Data;
uint64_t min(uint64_t a,uint64_t b){
    return a<b?a:b;
}
uint64_t max(uint64_t a,uint64_t b){
    return a>b?a:b;
}
int cmp(const void*a,const void*b){
    if(*(uint64_t*)a<*(uint64_t*)b){
        return 1;
    }else{
        return -1;
    }
}
uint64_t f(Data* d,int n,int subnum,int eleidx){
    uint64_t ret;
    if(eleidx==n){
        return d->count;
    }
    for(int i=0;i<subnum;i++){
        ret=(2*d->sub[i]+d->a[eleidx])*d->a[eleidx];   
        d->count+=ret;
        if(d->count<d->mini){
            d->sub[i]+=d->a[eleidx];
            d->mini=min(d->mini,f(d,n,subnum,eleidx+1));
            d->sub[i]-=d->a[eleidx];
        }
        d->count-=ret;
    }
    return d->mini;
}
int main(){
    int n,m;
    Data d;
    scanf("%d%d",&n,&m);
    uint64_t a[20],sub[10]={0},c=0;
    for(int i=0;i<10;i++){
        d.sub[i]=0;
    }
    for(int i=0;i<n;i++){
        scanf("%llu",&d.a[i]);
    }
    d.count=0;
    d.mini=UINT64_MAX;
    qsort(d.a,n,sizeof(uint64_t),cmp);
    uint64_t mini=f(&d,n,m,0);
    printf("%llu\n",mini);
    return 0;
}
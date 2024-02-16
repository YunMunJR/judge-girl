#include <stdio.h>
typedef struct num {
    int a;
    int b;
    int x;
}num_;
int TWO_OR_BIGGER(int x1) {
    int t = x1, a[11] = { 0 }, n = 0, num = 0, b[11] = { 0 },m=0; 
    int repeat = 0;
    while (t != 0){
        a[n] = t % 10;
        t /=10;
        n++;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m ; j++){
            if (a[i] == b[j]){
                repeat = 1; 
                break;
            }
        }
        if (repeat){
            repeat = 0; 
            if (i == 0){
                m++;
            }
        }else{
            b[m] = a[i];
            m++; 
            repeat = 0;
        }
    }
    return((m > 2) ? 0 : 1);
}
int main(){
    int a, b, x,t=0,tem=0;num_ nu[1000];
    while (scanf("%d %d %d", &a, &b, &x) != EOF){
        nu[t].a = a; nu[t].b=b; nu[t].x=x;
        t++;
    }
    for (int i = 0; i<t; i++){
        while (!TWO_OR_BIGGER(nu[i].x)){
            tem = ((nu[i].a % nu[i].b) * (nu[i].x % nu[i].b)) % nu[i].b;
            nu[i].x = tem;
            tem = 0;
        }
        if (i != t - 1){
            printf("%d\n", nu[i].x);
        }else{
            printf("%d", nu[i].x);
        }      
    }
    return 0;
}
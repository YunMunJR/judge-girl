#include <stdio.h>
int h(int x){
    if(x < 2){
        return -1;
    }else{
        return 2 + h(x-1) - h(x-2);
    }
}
int g(int x){
    if(x <= 2){
        return x*x - 1;
    }else{
        return 2;
    }
}
int f(int x){
    int h_val = h(x);
    int g_val = g(x);
    if(x > h_val){
        return f(x-1) - h_val;
    }else if(x < h_val){
        return f(g_val) - g_val;
    }else{
        return 1;
    }
}
int main(){
    int x;
    scanf("%d", &x);
    printf("%d\n", f(x));

    return 0;
}
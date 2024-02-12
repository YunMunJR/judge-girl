#include <stdio.h>
typedef struct cupr {
    int prev;
    int curr;
}cupr_;
int main(){
    cupr_ num = { 0.0 }, nu = { 0,0 }, sum = { 0,0 }, firstnum = { 0,0 };
    int n, gap, digit;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &digit);
        if (i == 0){
            num.prev = digit;
            nu.curr++;
            sum.curr += num.prev;
            firstnum.curr = num.prev;
        }else if (i == 1){
            num.curr = digit;
            gap = num.curr - num.prev;    
            sum.curr +=num.curr ;
            nu.curr++;
        }else{
            if (digit - num.curr == gap){
                num.prev = num.curr;
                num.curr = digit;
                sum.curr += num.curr;
                nu.curr++;
            }else{
                if (sum.curr > sum.prev){
                    sum.prev = sum.curr;
                    num.prev = num.curr;
                    num.curr = digit;
                    nu.prev = nu.curr;
                    firstnum.prev = firstnum.curr;
                    firstnum.curr = num.prev;
                    sum.curr = 0;
                    sum.curr += (num.curr + num.prev);
                    nu.curr = 2;
                    gap = num.curr - num.prev;
                }else if (sum.curr == sum.prev){
                    if (nu.curr > nu.prev){
                        num.prev = num.curr;
                        num.curr = digit;
                        nu.prev = nu.curr;
                        firstnum.prev = firstnum.curr;
                        firstnum.curr = num.prev;
                        sum.curr = 0;
                        sum.curr += (num.curr + num.prev);
                        nu.curr = 2;
                        gap = num.curr - num.prev;
                    }else if (nu.curr == nu.prev){
                        if (firstnum.curr > firstnum.prev){
                            num.prev = num.curr;
                            num.curr = digit;
                            firstnum.prev = firstnum.curr;
                            firstnum.curr = num.prev;
                            sum.curr = 0;
                            sum.curr += (num.curr + num.prev);
                            nu.curr = 2;
                            gap = num.curr - num.prev;
                        }else{
                            num.prev = num.curr;
                            num.curr = digit;
                            firstnum.curr = num.prev;
                            sum.curr = 0;
                            sum.curr += (num.curr + num.prev);
                            nu.curr = 2;
                            gap = num.curr - num.prev;
                        }
                    }else{
                        num.prev = num.curr;
                        num.curr = digit;
                        firstnum.curr = num.prev;
                        sum.curr = 0;
                        sum.curr += (num.curr + num.prev);
                        nu.curr = 2;
                        gap = num.curr - num.prev;
                    }
                }else{
                    num.prev = num.curr;
                    num.curr = digit;
                    firstnum.curr = num.prev;
                    sum.curr = 0;
                    sum.curr += (num.curr + num.prev);
                    nu.curr = 2;
                    gap = num.curr - num.prev;
                }
            }
        }
    }
    if (sum.curr > sum.prev){
        sum.prev = sum.curr;
        firstnum.prev = firstnum.curr;
        nu.prev = nu.curr;
    }else if (sum.curr == sum.prev){
        if (nu.curr > nu.prev){
            sum.prev = sum.curr;
            firstnum.prev = firstnum.curr;
            nu.prev = nu.curr;
        }else if (nu.curr == nu.prev){
            if (firstnum.curr > firstnum.prev){
                sum.prev = sum.curr;
                firstnum.prev = firstnum.curr;
                nu.prev = nu.curr;
            }
        }
    }
    if (sum.prev == 0){
        printf("%d %d %d", sum.curr, nu.curr, firstnum.curr);
    }else{
        printf("%d %d %d", sum.prev, nu.prev, firstnum.prev);
    }   
    return 0;
}
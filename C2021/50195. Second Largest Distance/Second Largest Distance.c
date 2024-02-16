#include <stdio.h>
#include <stdlib.h>
typedef struct f_and_s {
    int first;
    int second;
}fands;
typedef struct prcu_ {
    int prev;
    int curr;
}prcu;
int main(void){
    int num1_=0,num2_=0,num3_=0,digit,on1=0,on2=0,on3=0;
    int one_biggest_num, two_biggest_num, three_biggest_num;
    fands gap1 = { 0,0 }, gap2 = { 0,0 }, gap3 = { 0,0 },num1 = { 0,0 }, num2 = { 0,0 }, num3 = { 0,0 }; 
    prcu one = { 0,0 }, two = { 0,0 }, three = { 0,0 };
    while (scanf("%d", &digit) != EOF){
        num1_++; 
        num2_++; 
        num3_++;
        if (digit == 1){
            if (on1 == 0){
                on1++;
                one.curr = num1_;
            }else if(on1==1){
                on1++;
                gap1.first = num1_ - one.curr;
                num1.first = num1_;
                one.curr = num1_;
                one_biggest_num = num1_;
            }else{
                if (num1_ - one.curr > gap1.first){
                    gap1.second = gap1.first;
                    gap1.first = num1_ - one.curr;
                    one.curr = num1_;
                    num1.first = one_biggest_num;
                    one_biggest_num = num1_;
                }else if (num1_ - one.curr == gap1.first){
                    one_biggest_num = num1_;
                    one.curr = num1_;
                }else if (num1_ - one.curr >= gap1.second && num1_ - one.curr < gap1.first){
                    if (num1_ - one.curr == gap1.second){
                        one.curr = num1_;
                        num1.first = num1_;
                    }else{
                        gap1.second = num1_-one.curr;
                        one.curr = num1_;
                        num1.first = num1_;
                    }
                }else{
                    one.curr = num1_;
                }
            }
        }else if (digit == 2){
            if (on2 == 0){
                on2++;
                two.curr = num2_;
            }else if (on2 == 1){
                on2++;
                gap2.first = num2_ - two.curr;
                num2.first = num2_;
                two.curr = num2_;
                two_biggest_num = num2_;
            }else{
                if (num2_ - two.curr > gap2.first){
                    gap2.second = gap2.first;
                    gap2.first = num2_ - two.curr;
                    two.curr = num2_;
                    num2.first = two_biggest_num;
                    two_biggest_num = num2_;
                }else if (num2_ - two.curr == gap2.first){
                    two_biggest_num = num2_;
                    two.curr = num2_;
                }else if (num2_ - two.curr >= gap2.second && num2_ - two.curr < gap2.first){
                    if (num2_ - two.curr == gap2.second){
                        two.curr = num2_;
                        num2.first = num2_;
                    }else{
                        gap2.second = num2_ - two.curr;
                        two.curr = num2_;
                        num2.first = num2_;
                    }
                }else{
                    two.curr = num2_;
                }  
            }
        }else if (digit == 3){
            if (on3 == 0){
                on3++;
                three.curr = num3_;
            }else if (on3 == 1){
                on3++;
                gap3.first = num3_ - three.curr;
                num3.first = num3_;
                three.curr = num3_;
                three_biggest_num = num3_;
            }else{
                if (num3_ - three.curr > gap3.first){
                    gap3.second = gap3.first;
                    gap3.first = num3_ - three.curr;
                    three.curr = num3_;
                    num3.first = three_biggest_num;
                    three_biggest_num = num3_;
                }else if (num3_ - three.curr == gap3.first){
                    three_biggest_num = num3_;
                    three.curr = num3_;
                }else if (num3_ - three.curr >= gap3.second && num3_ - three.curr < gap3.first){
                    if (num3_ - three.curr == gap3.second){
                        three.curr = num3_;
                        num3.first = num3_;
                    }else{
                        gap3.second = num3_ - three.curr;
                        three.curr = num3_;
                        num3.first = num3_;
                    }
                }else{
                    three.curr = num3_;
                }   
            }
        }
    }
    printf("%d %d %d\n", gap1.second, num1.first -1- gap1.second, num1.first - 1);
    printf("%d %d %d\n",gap2.second, num2.first - 1 - gap2.second, num2.first - 1);
    printf("%d %d %d", gap3.second, num3.first - 1 - gap3.second, num3.first - 1);
    return 0;
}
#include <stdio.h>
typedef struct op {
    int prev;
    int curr;
}operator;
int main(){
    int num=0, sum1 = 0,sum2=1, digit; operator op={8,0};
    while (scanf("%d", &digit) != EOF){
        if (digit != 8 && digit != 9 && digit != 0){
            num = num * 10 + digit;
        }else if(digit==8||digit==9){        
            op.curr = digit;
            if (op.curr == op.prev){
                sum2 *= num;
                sum1 += sum2;
                num = 0;
                sum2 = 1;
            }else{
                sum2 *= num;
                num = 0;
            }
        }else{
            sum2 *= num;
            sum1 += sum2;
            printf("%d", sum1);
            break;
        }
    }
    return 0;
}
#include <stdio.h>
int what_number(char ch){
    switch (ch){
        case'0':
            return 0; 
        case'1':
            return 1; 
        case'2':
            return 2;
        case'3':
            return 3;
        case'4':
            return 4;
        case'5':
            return 5;
        case'6':
            return 6;
        case'7':
            return 7;
        case'8':
            return 8;
        case'9':
            return 9;
        case'-':
            return -1;
        default:
            return -2;
    }
}
int main(){
    char digit;
    static int two[20000] = { 0 }, three[20000] = { 0 }, five[20000] = { 0 }, eleven[20000] = { 0 };
    int sum = 0, num = 0, elesum = 0, exe = 1,times=0;
    while (scanf("%c", &digit, 1) != EOF){
        if (digit != '\n' && what_number(digit) != -1 && what_number(digit) != -2){
            sum += what_number(digit); num++;
            if (num % 2 != 0){
                elesum += what_number(digit);
            }else{
                elesum -= what_number(digit);
            }   
            two[times] = ((what_number(digit) % 2 == 0)) ? 1 : 0;
            three[times] = (sum % 3 == 0) ? 1 : 0;
            five[times] = (what_number(digit) == 0 || what_number(digit) == 5) ? 1 : 0;
            eleven[times] = (elesum % 11 == 0) ? 1 : 0;
        }
        if (digit == '\n'){
            sum = 0; 
            num = 0; 
            elesum = 0; 
            times++;
        }
        else if (what_number(digit) == -1){
            break;
        }    
    }
    for (int i = 0; i < times; i++){
        printf("%s %s %s %s", (two[i] == 1) ? "yes" : "no", (three[i] == 1) ? "yes" : "no", (five[i] == 1) ? "yes" : "no", (eleven[i] == 1) ? "yes" : "no");
        (i != times - 1)&&putchar('\n');
    }
    return 0;
}
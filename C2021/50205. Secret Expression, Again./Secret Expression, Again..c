#define MAXSIZE 1000000
#include <stdio.h>
#include <string.h>
int turn(char c) {
    if (c == '!' || c == '#' || c == '$' || c == '%'){
        return c - '!' + 1;
    }else if (c == '@'){
        return 2;
    }else if (c == '^'){
        return 6;
    }else if (c == ')'){
        return 0;
    }else{
        return c - '!' + 2;
    }
}
int main(){
    static char s[MAXSIZE + 1] = { '\0' }; int num = 1, sum = 0, numtemp = 0, length;
    scanf("%s", s);
    length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (s[i] != '*' && s[i] != '+'){
            numtemp = numtemp * 10 + turn(s[i]);
        }else {
            if (s[i] == '+'){ 
                num *= numtemp; 
                sum += num; 
                num = 1; 
                numtemp = 0; 
            }else{ 
                num *= numtemp; 
                numtemp = 0; 
            }
        }
        if (i == length - 1) {
            num *= numtemp; 
            sum += num;
        }
    }
    printf("%d", sum);
    return 0;
}
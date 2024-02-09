#include <stdio.h>
#include <stdint.h>
int main(){
    int col, row, n = 0; char zero, one, buf1, buf2; 
    uint32_t digit;
    scanf("%d%d%c", &row, &col,&buf1);
    scanf("%c%c%c", &one, &buf2, &zero);
    while (scanf("%u", &digit) != EOF){        
        for (int i = 31; i >= 0; i--){
            if (n % row == 0 && n != 0){
                putchar('\n');
            }
            n++;
            if (n > col * row){
                break;
            }
            printf("%c", ((1 << i) & digit) == 0 ? zero : one);
        }        
    }
    return 0;
}
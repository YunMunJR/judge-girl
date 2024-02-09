#include <stdio.h>
#include <string.h>
void print_up(char c, int width) {
    if (c == '1' || c == '4'){ 
        for (int i = 0; i < width; i++){
            putchar(' ');
        }
    }else{
        putchar(' ');
        for (int i = 0; i < width - 3; i++){
            printf("%c", c);
        }
        fputs("  ",stdout);
    }
}
void print_middleup(char c, int width) {
    if (c == '1' || c == '2' || c == '3'){
        for (int i = 0; i < width - 2; i++){
            putchar(' ');
        }
        printf("%c ", c);
    }else if (c == '5' || c == '6'){
        printf("%c", c);
        for (int i = 0; i < width - 1; i++){
            putchar(' ');
        }
    }else {
        printf("%c", c);
        for (int i = 0; i < width - 3; i++){
            putchar(' ');
        }
        printf("%c ", c);
    }
}
void print_middle(char c, int width) {
    if (!(c == '0' || c == '1' || c == '7')){
        putchar(' ');
        for (int i = 0; i < width - 3; i++){
            printf("%c", c);
        }
        fputs("  ",stdout);
    }
    else{ 
        for (int i = 0; i < width; i++){
            putchar(' ');
        } 
    }
}
void print_middledown(char c, int width) {
    if (c == '0' || c == '6' || c == '8') {
        printf("%c", c);
        for (int i = 0; i < width - 3; i++){
            putchar(' ');
        }
        printf("%c ", c);
    }else if (c == '2') {
        printf("%c", c);
        for (int i = 0; i < width - 1; i++){
            putchar(' ');
        }
    }else {
        for (int i = 0; i < width - 2; i++){
            putchar(' ');
        }
        printf("%c ", c);
    }
}
void print_down(char c, int width) {
    if (c == '1' || c == '4' || c == '7' || c == '9') {
        for (int i = 0; i < width; i++){
            putchar(' ');
        }
    }else {
        putchar(' ');
        for (int i = 0; i < width - 3; i++){
            printf("%c", c);
        }
        fputs("  ",stdout);
    }
}
int main() {
    char str[10]; int  width, height, len;
    while (scanf("%s%d%d", str, &width, &height) != EOF){
        len = strlen(str);
        for (int jj = 0; jj < len; jj++){ 
            print_up(str[jj], width); 
        }
        putchar('\n');
        for (int j = 0; j < (height - 2) / 2; j++) {
            for (int jj = 0; jj < len; jj++){ 
                print_middleup(str[jj], width); 
            }
            putchar('\n');
        }
        for (int jj = 0; jj < len; jj++){ 
            print_middle(str[jj], width); 
        }
        putchar('\n');
        for (int j = 0; j < (height - 2) / 2; j++) {
            for (int jj = 0; jj < len; jj++){ 
                print_middledown(str[jj], width); 
            }
            putchar('\n');
        }
        for (int jj = 0; jj < len; jj++){ 
            print_down(str[jj], width); 
        }
        putchar('\n');
    }
}
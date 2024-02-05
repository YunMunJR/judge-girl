 #include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <memory.h>
int main(){
    char s[128], abbr[128], nonabbr[8][128], upper;
    s[127] = '\0'; memset(abbr, 0, 128);
    int record = 0;
    for (int i = 0; i < 4; i++){
        nonabbr[i][127] = '\0';
    }
    strcpy(nonabbr[0], "of"); 
    strcpy(nonabbr[1], "and");
    strcpy(nonabbr[2], "the"); 
    strcpy(nonabbr[3], "at");
    strcpy(nonabbr[4], "of."); 
    strcpy(nonabbr[5], "and.");
    strcpy(nonabbr[6], "the."); 
    strcpy(nonabbr[7], "at.");
    while (scanf("%s", s) != EOF) {
        if (!strcmp(s, nonabbr[0]) || !strcmp(s, nonabbr[1]) || !strcmp(s, nonabbr[2]) || !strcmp(s, nonabbr[3])) {
            continue;
        }else {
            if (!strcmp(s, nonabbr[4])|| !strcmp(s, nonabbr[5]) || !strcmp(s, nonabbr[6]) || !strcmp(s, nonabbr[7])) {
                for (int i = 0; i < record; i++){
                    printf("%c", abbr[i]);
                }
                memset(abbr, 0, 127); 
                putchar('\n'); 
                record = 0;
            }
            else {
                upper = toupper(s[0]);
                abbr[record] = upper; 
                record++;
                if (s[strlen(s) - 1] == '.') {
                    for (int i = 0; i < record; i++){
                        printf("%c", abbr[i]);
                    }
                    memset(abbr, 0, 127); 
                    putchar('\n');
                    record = 0;
                }
            }
        }
    }
}
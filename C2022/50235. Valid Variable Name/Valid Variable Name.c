#include <stdio.h>
#include <string.h>
#include <ctype.h>
int hashf(char* s) {
    int val = 0;
    for (int i = 0; i < strlen(s); i++){
        val += (int)s[i];
    }
    val %= 1000;
    return val;
}
int main(){
    char hashstring[1000][3][21], s[21]; 
    int valid = 1, find = 1;
    int times[1000][3], num[1000] = { 0 }, hashvalue;
    s[20] = '\0';
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 3; j++) {
            hashstring[i][j][20] = '\0'; 
            times[i][j] = 0;
        }
    } 
    while (scanf("%s", s) != EOF) {
        valid = 1; find = 0; hashvalue = hashf(s);
        for (int i = 0; i < strlen(s); i++) {
            if (isalpha(s[i]) == 0 && isdigit(s[i]) == 0 && s[i] != '_'){
                valid = 0;
            }
        }
        if (isalpha(s[0]) == 0 && s[0] != '_'){
            valid = 0;
        }
        if (valid) {
            for (int i = 0; i < 3; i++) {
                if (strcmp(hashstring[hashvalue][i], s) == 0) {
                    times[hashvalue][i]++;
                    printf("%s %d\n",s,times[hashvalue][i]);
                    find = 1; 
                    break;
                }
            }
            if (!find) {       
                strcpy(hashstring[hashvalue][num[hashvalue]], s); 
                times[hashvalue][num[hashvalue]]++; 
                printf("%s %d\n", s, times[hashvalue][num[hashvalue]]);
                num[hashvalue]++;
            }
        }
    }
    return 0;
}
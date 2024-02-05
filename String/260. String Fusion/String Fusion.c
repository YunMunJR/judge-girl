 #include <stdio.h>
#include <string.h>
int main(){
    char s[128]; char str[128]; 
    memset(str, 0, 128);
    int slength = 0, idx,pair=1,first=0;
    while (scanf("%s", s) != EOF) {
        pair = 1;
        if (!first) {
            for (int i = 0; i < strlen(s); i++)str[i] = s[i]; first = 1; slength += strlen(s);
        }
        else {
            for (int i = 0; i < slength; i++) {
                pair = 1;
                for (int j = i; j < slength; j++) {
                    if (str[j] != s[j - i])pair = 0;
                }
                if (pair) {
                    idx = i;
                    for (int j = slength - i; j < strlen(s); j++) str[j + i] = s[j];
                    slength += (strlen(s) - slength + i); break;
                }
            }
            if (!pair) {
                for (int i = 0; i < strlen(s); i++) str[i + slength] = s[i];
                slength += strlen(s);
            }
        }       
    }
    for (int i = 0; i < slength; i++){
        printf("%c", str[i]);
    }
}
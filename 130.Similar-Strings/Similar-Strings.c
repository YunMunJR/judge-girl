 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    char s1[81], s2[81]; int num;
    s1[80] = '\0'; s2[80] = '\0';
    bool find, diff;
    scanf("%d", &num);
    for (int j = 0; j < num; j++) {
        scanf("%s%s", s1, s2);
        find = false; diff = false;
        int slen1 = strlen(s1), slen2 = strlen(s2);
        //printf("%d %d\n", slen1, slen2);
        int n = strcmp(s1, s2);
        //if (n == 0)printf("%s");
        if (n == 0)printf("yes\n");
        else {
            if (abs(slen1 - slen2) > 1)printf("no\n");
            else {
                if (slen1 == slen2) {
                    for (int i = 0; i < slen1; i++) {
                        if (find) {
                            if (s1[i] != s2[i]) { find = false; break; }
                        }
                        else {
                            if (s1[i] != s2[i]) {
                                if (s1[i] == s2[i + 1] && s1[i + 1] == s2[i]) { find = true; i++; }
                                else break;
                            }
                        }
                    }
                }
                else {
                    if (strncmp(s1, s2, min(slen1, slen2)) == 0)printf("yes\n");
                    else {
                        if (slen1 > slen2) {
                            for (int i = 0; i < slen2; i++) {
                                if (diff) {
                                    if (s1[i + 1] != s2[i]) { diff = false; break; }
                                }
                                else {
                                    if (s1[i] != s2[i]) {
                                        if (s1[i + 1] != s2[i])  break;
                                        else diff = true;
                                    }
                                }
                            }
                        }
                        else {
                            for (int i = 0; i < slen1; i++) {
                                if (diff) {
                                    if (s1[i] != s2[i + 1]) { diff = false; break; }
                                }
                                else {
                                    if (s1[i] != s2[i]) {
                                        if (s1[i] != s2[i + 1]) break;
                                        else diff = true;
                                    }
                                }
                            }
                        }
 
                    }
                }
                if (strncmp(s1, s2, min(slen1, slen2)) != 0) {
                    if (find || diff) printf("yes\n");
                    else printf("no\n");
                }
            }        
        }        
    }
    return 0;
}

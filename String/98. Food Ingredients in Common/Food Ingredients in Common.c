 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data {
    char food[70];
    int ingrenum;
    char ingredient[10][70];
}data;
int main() {
    int n, m, q1num, q2num, find, t;
    char q[2][70], str[70], cmd[140], * start = NULL, del[] = " ", * ptr = NULL,c;
    scanf("%d", &n);
    data* f = (data*)malloc(n * sizeof(data));
    for (int i = 0; i < n; i++) {
        scanf("%s", f[i].food);
        scanf("%d", &f[i].ingrenum);
        for (int j = 0; j < f[i].ingrenum; j++) {
            scanf("%s", f[i].ingredient[j]);
        }
        for (int j = 0; j < f[i].ingrenum; j++) {
            for (int k = j + 1; k < f[i].ingrenum; k++) {
                if (strcmp(f[i].ingredient[j], f[i].ingredient[k]) > 0) {
                    strcpy(str, f[i].ingredient[j]);
                    strcpy(f[i].ingredient[j], f[i].ingredient[k]);
                    strcpy(f[i].ingredient[k], str);
                }
            }
        }
    }
    scanf("%d", &m);
    scanf("%c", &c);
    for (int i = 0; i < m; i++) {
        q1num = -1; 
        q2num = -1; 
        find = 0;
        scanf("%s", q[0]); 
        scanf("%s", q[1]);
        for (int j = 0; j < n; j++) {
            if (!strcmp(f[j].food, q[0])){
                q1num = j;
            }
            if (!strcmp(f[j].food, q[1])){
                q2num = j;
            }
            if (q1num >= 0 && q2num >= 0){
                break;
            }
        }
        for (int j = 0; j < f[q1num].ingrenum; j++) {
            for (int k = 0; k < f[q2num].ingrenum; k++) {
                if (!strcmp(f[q1num].ingredient[j], f[q2num].ingredient[k])) {
                    if (find){
                        putchar(' ');
                    }
                    printf("%s", f[q1num].ingredient[j]); 
                    find = 1;
                }
            }
        }
        if (!find){
            fputs("nothing",stdout);
        }
        putchar('\n');
    }
    free(f);
}
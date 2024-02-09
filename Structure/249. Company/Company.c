#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct employee {
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
}employee;
typedef struct command {
    char first_name1[32];
    char last_name1[32];
    char first_name2[32];
    char last_name2[32];
}command;
typedef struct returnvalue {
    int re;
    int boss_id;
}returnvalue;
returnvalue findsub(const employee* em,int emnum,command command,int idx1) {
    int idx = idx1; returnvalue re;
    while (strcmp(em[idx].first_name, command.first_name2) != 0 || strcmp(em[idx].last_name, command.last_name2) != 0) {
        if (em[idx].boss_id == em[idx].id){ 
            re.boss_id = em[idx].boss_id; re.re = 0; 
            return re; 
        }else {
            for (int i = 0; i < emnum; i++) {
                if (em[i].id == em[idx].boss_id){ 
                    idx = i; 
                    break; 
                }
            }
        }
    }
    re.boss_id = em[idx].id; 
    re.re = 1;
    fputs("subordinate",stdout);
    return re;
}
returnvalue findsup(const employee* em, int emnum, command command, int idx2) {
    int idx = idx2; returnvalue re;
    while (strcmp(em[idx].first_name, command.first_name1) != 0 || strcmp(em[idx].last_name, command.last_name1) != 0) {
        if (em[idx].boss_id == em[idx].id){ 
            re.boss_id = em[idx].boss_id; 
            re.re = 0; 
            return re; 
        }else {
            for (int i = 0; i < emnum; i++) {
                if (em[i].id == em[idx].boss_id){ 
                    idx = i; 
                    break; 
                }
            }
        }
    }
    re.boss_id = em[idx].id; 
    re.re = 1;
    fputs("supervisor",stdout);
    return re;
}
int main(){
    int n, m, idx1, idx2;
    char c;
    returnvalue val1, val2;
    scanf("%d", &n);
    employee* em = (employee*)malloc(n * sizeof(employee));
    command command;
    for (int i = 0; i < n; i++) {
        scanf("%d", &em[i].id);
        scanf("%s", em[i].first_name);
        scanf("%s", em[i].last_name);
        scanf("%d", &em[i].boss_id);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        idx1 = -1; idx2 = -1;
        scanf("%s", command.first_name1); 
        scanf("%s", command.last_name1);
        scanf("%s", command.first_name2); 
        scanf("%s", command.last_name2);
        for (int j = 0; idx1 < 0 || idx2 < 0; j++) {
            if (idx1 < 0) {
                if (!strcmp(command.first_name1, em[j].first_name) && !strcmp(command.last_name1, em[j].last_name)){
                    idx1 = j;
                }
            }
            if (idx2 < 0) {
                if (!strcmp(command.first_name2, em[j].first_name) && !strcmp(command.last_name2, em[j].last_name)){
                    idx2 = j;
                }
            }
        }
        val1 = findsub(em, n, command, idx1);
        if (!val1.re) {
            val2 = findsup(em, n, command, idx2);
            if (!val2.re) {
                if (val1.boss_id == val2.boss_id){
                    fputs("colleague",stdout);
                }else{
                    fputs("unrelated",stdout);
                }
            }
        }
        (i != m - 1)&&putchar('\n');
    }
    free(em);
}
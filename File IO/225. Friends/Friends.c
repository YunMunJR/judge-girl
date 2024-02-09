#include <stdio.h>
#include <assert.h>
#include <string.h>
struct person {
    unsigned int id;
    char name[32];
};
typedef struct person person;
struct friends {
    unsigned id1;
    unsigned id2;
};
typedef struct friends friends;
int power(int base, int exp) {
    int re = 1;
    for (int i = 0; i < exp; i++){
        re *= base;
    }
    return re;
}
int main(){
    FILE* fp; char filename[] = "friends", cmd[50], p1[50], p2[50]; int P = 0, F = 0, c, count = 0, find = 0;
    unsigned p1id = 10000, p2id = 10000;
    static person p[10000];
    static friends f[10000];
    fp = fopen(filename, "rb");
    for (int i = 0; i < 4; i++) {
        c = fgetc(fp);
        P += c * power(256, i);
    }
    fread(p, sizeof(person), P, fp);
    for (int i = 0; i < 4; i++) {
        c = fgetc(fp);
        F += c * power(256, i);
    }
    fread(f, sizeof(friends), F, fp);
    scanf("%s", cmd);
    while (strcmp(cmd, "end") != 0) {
        if (!(count % 2)) {
            strcpy(p1, cmd); count++;
        }else {
            strcpy(p2, cmd); count++; find = 0; p1id = 10000; p2id = 10000;
            for (int i = 0; p1id > 9999 || p2id > 9999; i++) {
                if (!strcmp(p[i].name, p1) || !strcmp(p[i].name, p2)){
                    if(p1id > 9999){
                        p1id = p[i].id;
                    }else{ 
                        p2id = p[i].id; 
                        break; 
                    }
                }
            }         
            for (int i = 0; i < F; i++) {
                if ((p1id == f[i].id1 && p2id == f[i].id2) || (p2id == f[i].id1 && p1id == f[i].id2)){ 
                    find = 1; 
                    break; 
                }
            }
            printf("%s\n",(find)?"yes":"no");
        }
        scanf("%s", cmd);
    }
    fclose(fp);
}
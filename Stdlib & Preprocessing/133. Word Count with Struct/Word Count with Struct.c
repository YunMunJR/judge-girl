#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct string_count {
    char seen[80];
    int count;
};
int cmp(const void*a,const void*b){
    struct string_count c=*(struct string_count*)a,d=*(struct string_count*)b;
    if(c.count!=d.count){
        if(c.count>d.count){
            return 1;
        }else{
            return -1;
        }
    }else{
        return (strcmp(c.seen,d.seen));
    }
}
int compare_and_add(char *string, struct string_count strings[]) {
    int c=0,find=0;
    while(strings[c].count!=0){
        if(!strcmp(strings[c].seen,string)){
            strings[c].count++;
            find=1;
            break;
        }
        c++;
    }
    if(!find){
        strcpy(strings[c].seen,string);
        strings[c].count=1;
    }
    return find;
}
void sort(struct string_count strings[]) {
    int c=0;
    while(strings[c].count!=0){
        c++;
    }
    qsort(strings,c,sizeof(struct string_count),cmp);
}
void print(struct string_count strings[]) {
    int c=0;
    while(strings[c].count!=0){
        printf("%d %s\n",strings[c].count,strings[c].seen);
        c++;
    }
}
int compare_and_add(char *string, struct string_count strings[]);
void sort(struct string_count strings[]);
void print(struct string_count strings[]);
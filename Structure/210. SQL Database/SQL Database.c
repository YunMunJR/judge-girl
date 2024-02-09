#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct data {
    char firstname[81];
    char lastname[81];
    char id[81];
    int salary;
    int age;
}Data;
typedef struct command {
    char cmd[256];
    char field[13][81];
    int fieldtonum[13];
    int compidx;
    int num;
}Command;
int fieldcomp(char* fieldcon) {
    if (fieldcon[0] == 'l'){
        return 0;
    }else if (fieldcon[0] == 'f'){
        return 1;
    }else if (fieldcon[0] == 'I'){
        return 2;
    }else if (fieldcon[0] == 's'){
        return 3;
    }else{
        return 4;
    }
}
int strornum(char* fieldcon) {
    if (fieldcon[0] == 'l' || fieldcon[0] == 'f' || fieldcon[0] == 'I'){
        return 0;
    }else{
        return 1;
    }
}
int stringoperator(char* s) {
    if (s[0] == '='){
        return 0;
    }else{
        return 1;
    }
}
int numoperator(char* s) {
    if (s[0] == '='){
        return 0;
    }else if (s[0] == '>'){
        return 1;
    }else{
        return 2;
    }
}
void printfield(Data person[], Command command, int personidx,int fieldnum) {
    for (int i = 1; i < fieldnum - 4; i++) { 
        switch (command.fieldtonum[i]) {
            case 0:
                fputs(person[personidx].lastname, stdout);
                putchar(' ');
                break;
            case 1:
                fputs(person[personidx].firstname, stdout); 
                putchar(' ');
                break;
            case 2:
                fputs(person[personidx].id, stdout); 
                putchar(' '); 
                break;
            case 3:
                printf("%d ", person[personidx].salary); 
                break;
            default:
                printf("%d ", person[personidx].age);
        }
    }
    putchar('\n');
}
void processstring(Data person[], Command command, int datanum, int fieldnum, char* string , int stringop) {
    for (int i = 0; i < datanum; i++) {
        if (command.compidx == 0){ 
            if (stringop == 0 && !strcmp(person[i].lastname, string)){
                printfield(person, command, i, fieldnum);
            }else if (stringop == 1 && strcmp(person[i].lastname, string) != 0){
                printfield(person, command, i, fieldnum);
            }
        }else if(command.compidx == 1){
            if (stringop == 0 && !strcmp(person[i].firstname, string)){
                printfield(person, command, i, fieldnum);
            }else if (stringop == 1 && strcmp(person[i].firstname, string) != 0){
                printfield(person, command, i, fieldnum);
            }
        }else {
            if (stringop == 0 && !strcmp(person[i].id, string)){
                printfield(person, command, i, fieldnum);
            }else if(stringop == 1 && strcmp(person[i].id, string) != 0){
                printfield(person, command, i, fieldnum);
            }
        }
    }
}
void proccessnum(Data person[],Command command, int datanum, int fieldnum,int numop) { 
    for (int i = 0; i < datanum; i++) {
        if (command.compidx == 3) {
            if (numop == 0 && person[i].salary == command.num){
                printfield(person, command, i, fieldnum);
            }else if (numop == 1 && person[i].salary > command.num){
                printfield(person, command, i, fieldnum);
            }else if (numop == 2 && person[i].salary < command.num){
                printfield(person, command, i, fieldnum);
            }
        }else {
            if (numop == 0 && person[i].age == command.num){
                printfield(person, command, i, fieldnum);
            }else if (numop == 1 && person[i].age > command.num){
                printfield(person, command, i, fieldnum);
            }else if (numop == 2 && person[i].age < command.num){
                printfield(person, command, i, fieldnum);
            }
        }
    }
}
int main(){
    int datanum, searchnum, fieldnum = 0,numop, stringop;
    char* s, * start, del[] = " ", * ptr = NULL,c;
    Data person[50]; Command command;
    scanf("%d", &datanum);
    for (int i = 0; i < datanum; i++) {
        scanf("%s", person[i].lastname);
        scanf("%s", person[i].firstname);
        scanf("%s", person[i].id);
        scanf("%d", &person[i].salary);
        scanf("%d", &person[i].age);
    }
    scanf("%d", &searchnum);
    for (int i = 0; i < searchnum; i++) {
        command.num = 0; fieldnum = 0;
        scanf("%c", &c);
        fgets(command.cmd, 256, stdin);      
        start = strtok(command.cmd, del);
        while (start) {
            strcpy(command.field[fieldnum], start); 
            fieldnum++;
            start = strtok(NULL, del);
        }
        command.field[fieldnum - 1][strlen(command.field[fieldnum - 1]) - 1] = '\0';
        if (strornum(command.field[fieldnum - 3])){
            sscanf(command.field[fieldnum - 1], "%d", &command.num);
        }
        for (int j = 1; j < fieldnum - 3; j++){
            command.fieldtonum[j] = fieldcomp(command.field[j]);
        }
        command.compidx = fieldcomp(command.field[fieldnum - 3]);
        if (command.compidx == 0 || command.compidx == 1 || command.compidx == 2) {
            stringop = stringoperator(command.field[fieldnum - 2]);
            processstring(person, command, datanum, fieldnum, command.field[fieldnum - 1], stringop);
        }else {
            numop = numoperator(command.field[fieldnum - 2]);
            proccessnum(person, command, datanum, fieldnum, numop);
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum operator{
    ADD,SUB,MUL,DIV,MOD,EQL,NOTEQL,SMALLER,LARGER,SMALLEREQUAL,LARGEREQUAL
};
enum statementtype{
    STOP,IF,GOTO,PRINT,ASSIGN
};
#define MAXVARLEN 8
typedef struct variable{
    char name[MAXVARLEN];
    int value;
}Variable;
#define VAR 100
typedef struct variableset{
    Variable variables[VAR];
    char *varNameTable[VAR];
}Variableset;
typedef struct statement{
    int code;
    int op1,op2,compopr; //IF
    int gotoline; // GOTO
    int target;    //ASSIGN and PRINT 
}Statement;
int find(char* first,char* firsttable[]){
    int re=0;
    while(firsttable[re]){
        if(!strcmp(first,firsttable[re])){
            return re;
        }
        re++;
    }
    return -1;
}
int findOprCode(char* name){
    char *operators[]={"+","-","*","/","%","==","!=","<",">","<=",">=",NULL};
    int code=find(name,operators);
    if(code==-1){
        exit(-1);
    }
    return code;
}
int findVariables(char* opd,Variableset* variableSet){
    int re=0;
    while(variableSet->varNameTable[re]){
        if(!strcmp(opd,variableSet->varNameTable[re])){
            return re;
        }
        re++;
    }
    return -1;
}
void processIF(Variableset* variableSet,Statement *statement){
    char gotostr[MAXVARLEN];
    char opd[MAXVARLEN],opr[MAXVARLEN];
    statement->code=IF;
    scanf("%s",opd);
    statement->op1=findVariables(opd,variableSet);
    scanf("%s",opr);
    statement->compopr=findOprCode(opr);
    scanf("%s",opd);
    statement->op2=findVariables(opd,variableSet);
    scanf("%s",gotostr);
    scanf("%d",&(statement->gotoline));
}
void processASSIGN(Statement* statement,char* first, Variableset* variableSet){
    char opd[MAXVARLEN],opr[MAXVARLEN];
    statement->target=findVariables(first,variableSet);
    char assignstr[MAXVARLEN];
    scanf("%s",assignstr);
    scanf("%s",opd);
    statement->op1=findVariables(opd,variableSet);
    scanf("%s",opr);
    statement->compopr=findOprCode(opr);
    scanf("%s",opd);
    statement->op2=findVariables(opd,variableSet);    
}
void processcode(Variableset* variableSet,Statement statements[]){
    char first[MAXVARLEN],opd[MAXVARLEN];
    char* firsttable[]={"STOP","IF","GOTO","PRINT",NULL};
    Statement* statement=&(statements[1]); 
    while(scanf("%s",first)!=EOF){     
        //fprintf(stderr,"%s ",first);
        int firsttype=find(first,firsttable);
        switch (firsttype){
            case STOP:
                statement->code=STOP;break;
            case IF:
                statement->code=IF;
                processIF(variableSet,statement);break;
            case GOTO:
                statement->code=GOTO;
                scanf("%d",&(statement->gotoline));break;
            case PRINT:
                statement->code=PRINT;
                scanf("%s",opd);
                statement->target=findVariables(opd,variableSet);break;
            default:
                statement->code=ASSIGN;
                processASSIGN(statement,first,variableSet);break;
        }
        statement++;
    }
}
int compare(int operand1,int operand2,int operator){
    switch(operator){
        case EQL:
            return operand1==operand2;
        case NOTEQL:
            return operand1!=operand2;
        case SMALLER:
            return operand1<operand2;
        case LARGER:
            return operand1>operand2;
        case SMALLEREQUAL:
            return operand1<=operand2;
        case LARGEREQUAL:
            return operand1>=operand2;
        default:
            exit(-1);
    }
}
int airthmetic(int operand1,int operand2,int operator){
    switch (operator){
        case ADD:
            return operand1+operand2;
        case SUB:
            return operand1-operand2;
        case MUL:
            return operand1*operand2;
        case DIV:
            return operand1/operand2;
        case MOD:
            return operand1%operand2;
        default:
            exit(-1);
    }
}
void runcode(Variableset* variableSet,Statement statements[]){
    int line=1,cc=0;
    Statement* statement=&(statements[line]);
    Variable *vars=variableSet->variables;
    while(statement->code!=STOP){
        switch (statement->code){
            case IF:
                if(compare(vars[statement->op1].value,vars[statement->op2].value,statement->compopr)){
                    //
                    line=statement->gotoline;
                }else{
                    line++;
                }
                break;
            case GOTO:
                line=statement->gotoline;break;
            case ASSIGN:
                vars[statement->target].value=
                airthmetic(vars[statement->op1].value,vars[statement->op2].value,statement->compopr);
                line++;break;
            case PRINT:
                printf("%d",vars[statement->target].value);
                putchar('\n');
                line++;
                break;
            default:
                exit(-1);
        }
        cc++;
        statement=&(statements[line]);
    }
}
void readvariables(Variableset* variableSet){
    int count=0;
    char name[MAXVARLEN];
    scanf("%s",name);
    while(strcmp(name,"END")!=0){
        char eql[MAXVARLEN];
        Variable*variable=&(variableSet)->variables[count];
        strcpy(variable->name,name);
        scanf("%s",eql);
        variableSet->varNameTable[count]=variable->name;
        scanf("%d",&(variable)->value);
        scanf("%s",name);
        count++;
    }
    variableSet->varNameTable[count]=NULL;
}
#define LINE 1001
#define v 2
int main(){
    int c=0;
    Variableset variableSet;
    readvariables(&variableSet);
    Statement statements[LINE];
    processcode(&variableSet,statements);
    runcode(&variableSet,statements);
    return 0;
}
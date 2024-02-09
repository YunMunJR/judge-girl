 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
typedef struct treenode {
    char expression[33];
    int val;
    struct treenode* left;
    struct treenode* right;
}treenode;
 
int isoperator(char* operator[], char* string) {
    int index = 0, re = 0;
    while (1) {
        if (!strcmp(string, operator[index])) { 
            re = 1; 
            return re;
        }
        index++;
        if (index > 3){
            break;
        }
    }
    return re;
}
 
treenode* gennode(char expre[][33], int idx) {
    treenode* node = (treenode*)malloc(sizeof(treenode));
    assert(node);
    strcpy(node->expression, expre[idx]);
    node->val = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}
 
void insert(treenode* root, char expre[][33], char* operator[],int maxcount) {
    static int idx = 1; 
    if (!isoperator(operator,expre[idx - 1]))return;
    root->left = gennode(expre, idx); idx++;    
    insert(root->left, expre, operator,maxcount);  
    root->right = gennode(expre, idx); idx++;
    insert(root->right, expre, operator,maxcount);
}
 
int solve(treenode* root, char* operators[]) {
    if (isoperator(operators,root->expression)) {
        if (!strcmp(operators[0], root->expression)){
            return (solve(root->left, operators) + solve(root->right, operators));
        }else if (!strcmp(operators[1], root->expression)){
            return (solve(root->left, operators) - solve(root->right, operators));
        }else if (!strcmp(operators[2], root->expression)){
            return (solve(root->left, operators) * solve(root->right, operators));
        }else{
            return (solve(root->left, operators) / solve(root->right, operators));
        }        
    }else {
        int val;
        sscanf(root->expression, "%d", &val);
        return val;
    }
}
 
int main(){
    char* operator[] = { "+","-","*","/" }, s[33];
    char variable[33], equal[2], value[33];
    char expre[1000][33];
    int leftblanknum = 0, exprecount = 0, variablecount = 0, find;
    treenode* root; 
    scanf("%s", s);
    if (!strcmp(s, "(")){
        leftblanknum++;
    }else{ 
        strcpy(expre[exprecount], s); 
        exprecount++; 
    }
    while (leftblanknum > 0) { 
        find = 0;
        scanf("%s", s);
        if (!strcmp(s, "(")){
            leftblanknum++;
        }else if (!strcmp(s, ")")){
            leftblanknum--;
        }else {
            if (!isdigit(s[0]) && !isoperator(operator,s)) {
                for (int i = 0; i < exprecount; i++) {
                    if (!strcmp(s, expre[i])){ 
                        find = 1; break; 
                    }
                }
                if (!find){
                    variablecount++;
                }
            }           
            strcpy(expre[exprecount], s); exprecount++;
        } 
    }  
    for (int i = 0; i < variablecount; i++) {     
        scanf("%s%s%s", variable, equal, value);
        for (int j = 0; j < exprecount; j++) {
            if (!strcmp(variable, expre[j])){
                strcpy(expre[j], value);
            }
        }
    }
    root = gennode(expre, 0);
    insert(root, expre, operator,exprecount);
    printf("%d", solve(root, operator));
}
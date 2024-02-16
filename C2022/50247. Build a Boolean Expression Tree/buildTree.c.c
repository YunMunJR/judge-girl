#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct Node{
    char* val;
    struct Node *left, *right;
} Node;
typedef struct{
    Node* p[500000];
    int num;
}Parent;
Node* gennode(){
    Node*node;
    node=(Node*)malloc(sizeof(Node));
    node->val=NULL;
    node->left=NULL;
    node->right=NULL;
    return node;
}
int find(char* table[],char* s){
    int c=0;
    while(table[c]){
        if(!strcmp(table[c],s)){
            return c;
        }
        c++;
    }
    return -1;
}
Node* buildTree(char* expr){
    Node *root,*ptr;
    Parent pa;
    pa.num=0;
    root=gennode();
    ptr=root;
    char* st;
    static char s[1000001][5];
    char* table[]={"!","&&","||","(",")",NULL};
    int c=0,i=0,start=0,end;
    st=strtok(expr," \n");
    while(st){
        strcpy(s[c],st);
        if(find(table,s[c])==0){
            ptr->val=s[c];
            ptr->left=gennode(); 
            ptr=ptr->left;
        }else if(find(table,s[c])==3){
            pa.p[pa.num]=ptr;
            pa.num++;
            ptr->left=gennode();
            ptr=ptr->left;
        }else if(find(table,s[c])==4){
            
        }else if(find(table,s[c])==2||find(table,s[c])==1){
            ptr=pa.p[pa.num-1];
            pa.num--;
            ptr->val=s[c];
            ptr->right=gennode();
            ptr=ptr->right;
        }else{
            ptr->val=s[c];
        }
        c++;
        st=strtok(NULL," \n");
    }
    return root; 
}
Node* buildTree(char* expr);
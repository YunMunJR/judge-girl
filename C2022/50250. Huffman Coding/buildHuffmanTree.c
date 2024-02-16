#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "huffmanTree.h"
int cmp(const void*a,const void*b){
    Node** c=*(Node***)a,**d=*(Node***)b;
    if((*c)->frequency!=(*d)->frequency){
        if((*c)->frequency>(*d)->frequency){
            return 1;
        }else{
            return -1;
        }
    }else{
        return strcmp((*c)->symbol,(*d)->symbol);
    }
}
int cmp2(const void*a,const void*b){
    return strcmp(*(char**)a,*(char**)b);
}
Node* gennode(char* s,int freq){
    Node* node;
    node=(Node*)malloc(sizeof(Node));
    strcpy(node->symbol,s);
    node->frequency=freq;
    node->left=NULL;
    node->right=NULL;
    return node;
}
void build(Node** nodeptrset[],int c,int cc){
    Node* root;
    if(cc==c-1){
        return;
    }
    char* min;
    qsort(nodeptrset+cc,c-cc,sizeof(Node**),cmp);
    min=(strcmp((*nodeptrset[cc])->symbol,(*nodeptrset[cc+1])->symbol))>0?(*nodeptrset[cc+1])->symbol:(*nodeptrset[cc])->symbol;
    root=gennode(min,(*nodeptrset[cc])->frequency+(*nodeptrset[cc+1])->frequency);
    root->left=(*nodeptrset[cc+1]);
    root->right=(*nodeptrset[cc]);
    (*nodeptrset[cc+1])=root;
    build(nodeptrset,c,cc+1);
    return;
}
Node* buildHuffmanTree(char* s[SYM_MAX_NUM], int n){
    Node *node[n];
    qsort(s,n,sizeof(char*),cmp2);
    int c=1;
    node[0]=gennode(s[0],1);
    for(int i=1;i<n;i++){
        if(!strcmp(s[i],s[i-1])){
            node[c-1]->frequency++;
        }else{
            c++;
            node[c-1]=gennode(s[i],1);
        }
    }
    Node*root,**nodeptr[c];
    for(int i=0;i<c;i++){
        nodeptr[i]=&node[i];
    }
    build(nodeptr,c,0);
    return (*nodeptr[c-1]);
}
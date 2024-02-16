#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "HuffmanDecoding.h"
void print(Node* root,char* data,int* c,int slen,char rec[100][100],int* snum){
    if((!root->left)&&(!root->right)){
        strcpy(rec[*snum],root->symbol);
        (*snum)++;
        if((*c)==slen){
            for(int i=0;i<(*snum);i++){
                printf("%s",rec[i]);
#ifdef SPACE
    putchar(' ');
#endif
#ifdef NEWLINE
    putchar('\n');
#endif
            }
        }  
    }else{         
        if((*c)==slen){
            fputs("-1",stdout);
#ifdef SPACE
    putchar(' ');
#endif
#ifdef NEWLINE
    putchar('\n');
#endif
        }else{
            if(data[*c]=='0'){
                (*c)++;
                print(root->left,data,c,slen,rec,snum);
            }else{
                (*c)++;
                print(root->right,data,c,slen,rec,snum);
            } 
        }   
    }
    return;
}
void HuffmanDecoding(Node *root, char *data){
    char rec[100][100];
    int c=0,snum=0;
    while(c<strlen(data)){
        print(root,data,&c,strlen(data),rec,&snum);
    }
}
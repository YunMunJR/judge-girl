#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {HLHR, HRHL};
typedef struct node{
    int num; 
    struct node* parent;
    struct node* left;
    struct node* right;
}treenode;
treenode* gennode(treenode*parent){
    treenode* node;
    node=(treenode*)malloc(sizeof(treenode));
    node->num=-1;
    node->parent=parent;
    node->left=NULL;
    node->right=NULL;
    return node;
}
void print(treenode* root,int cmd){
    if(cmd==HLHR){
        printf("%d\n",root->num);
        if(root->left){
            print(root->left,HRHL);
        }
        printf("%d\n",root->num);
        if(root->right){
            print(root->right,HRHL);
        }
    }else{
        printf("%d\n",root->num);
        if(root->right){
            print(root->right,HLHR);
        }
        printf("%d\n",root->num);
        if(root->left){
            print(root->left,HLHR);
        }
    }
}
int main(){
    int numc=0;
    char buf[5000],*ptr=buf,num[5];
    memset(buf,0,5000);
    fread(buf,5000,sizeof(char),stdin);
    treenode* root,*nodeptr;
    root=gennode(root);
    nodeptr=root;
    while(*ptr!='\n'&&*ptr!='\0'){
        if(*ptr=='('){
            nodeptr->left=gennode(nodeptr);
            nodeptr=nodeptr->left;
        }else if(*ptr==')'){
            if(num[0]!='\0'){
                num[numc]='\0';
                numc=0;
                nodeptr->num=atoi(num);
                num[0]='\0';
            }
            nodeptr=nodeptr->parent;
            nodeptr->num=nodeptr->left->num+nodeptr->right->num;
        }else if(*ptr==','){
            if(num[0]!='\0'){
                num[numc]='\0';
                numc=0;
                nodeptr->num=atoi(num);
                num[0]='\0';
            }           
            nodeptr=nodeptr->parent;
            if(!nodeptr->right){
                nodeptr->right=gennode(nodeptr);
            }
            nodeptr=nodeptr->right;
        }else{
            num[numc]=*ptr;
            numc++;
        }
        ptr++;
    }
    print(root,HLHR);
    return 0;
}
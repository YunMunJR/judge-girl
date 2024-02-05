#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char cmd[15];
    char c[2];
    char num[15];
}insert;
typedef struct treenode{
    char c;
    int cnum;
    int lnum;
    int rnum;
    struct treenode*left;
    struct treenode*right;
}treenode;
int max(int a,int b){
    return (a>b)?a:b;
}
treenode*gennode(char c,int cnum){
    treenode*node;    
    node=(treenode*)malloc(sizeof(treenode));
    node->c=c;
    node->cnum=cnum;
    node->lnum=0;
    node->rnum=0;
    return node;
}
void ins1(treenode**root,char c,int dir,int cnum){ // insert left right
    if(!dir){
        if(*root){
            (*root)->lnum+=cnum;
            ins1(&(*root)->left,c,dir,cnum);
        }else{
            *root=gennode(c,cnum);
        }
    }else{
        if(*root){
            (*root)->rnum+=cnum;
            ins1(&(*root)->right,c,dir,cnum);
        }else{
            *root=gennode(c,cnum);
        }
    }
}
void ins2(treenode**root,int idx,char c,int cnum){ // insert specific position
    if(!(*root)){
        (*root)=gennode(c,cnum);
    }else{
        if(idx>(*root)->lnum+(*root)->cnum+1){
            (*root)->rnum+=cnum;
            ins2(&(*root)->right,idx-(*root)->lnum-(*root)->cnum,c,cnum);
        }else if(idx<(*root)->lnum+1){
            (*root)->lnum+=cnum;
            ins2(&(*root)->left,idx,c,cnum);
        }else{
            treenode*node1,*node2;
            if(idx==(*root)->lnum+1||idx==(*root)->lnum+(*root)->cnum+1){           
                if((*root)->c==c){
                    (*root)->cnum+=cnum;
                }else{
                    if(idx==(*root)->lnum+1){  
                        (*root)->lnum+=cnum;
                        ins1(&(*root)->left,c,1,cnum);     
                    }else{
                        (*root)->rnum+=cnum;
                        ins1(&(*root)->right,c,0,cnum);         
                    }
                }     
            }else{
                if((*root)->c==c){
                    (*root)->cnum+=cnum;
                }else{
                    int num=idx-(*root)->lnum-1,ret=(*root)->cnum-num;
                    (*root)->lnum+=num;
                    (*root)->rnum+=ret;
                    ins1(&(*root)->left,(*root)->c,1,num);
                    ins1(&(*root)->right,(*root)->c,0,ret);
                    (*root)->c=c;
                    (*root)->cnum=cnum;          
                }       
            }
        }
    }
}
void print(treenode*root,int totalndnum,char* last,int *num,int* cnum){
    if(root->left)print(root->left,totalndnum,last,num,cnum);
    if(root->c!=*last){
        if(*last!='\0'){
            printf("%c",*last);
            putchar(' ');
            printf("%d",*cnum);
            putchar(' ');
        }
        *last=root->c;
        *cnum=root->cnum;
    }
    else{
        (*cnum)+=root->cnum;
    }
    (*num)+=root->cnum;
    if(*num==totalndnum){
        printf("%c",*last);
        putchar(' ');
        printf("%d",*cnum);
        putchar(' ');
    }
    if(root->right)print(root->right,totalndnum,last,num,cnum);
}
int main(){
    char cmd[10],*st,buf[8000000];
    int n=0,chnum=0,cc=0,total=0;
    int a[26];
    insert i;
    treenode* root;
    //node=gennode('\0');
    for(int i=0;i<26;i++)a[i]=0;
    fread(buf,1,8000000,stdin);
    st=strtok(buf," \n");
    while(st){
        strcpy(cmd,st);  
        if(!strcmp(cmd,"insert")){
            st=strtok(NULL," \n");
            strcpy(i.cmd,st);
            st=strtok(NULL," \n");
            strcpy(i.c,st);
            st=strtok(NULL," \n");
            strcpy(i.num,st);
            char c;
            int num,idx=0;          
            if(i.cmd[0]>='0'&&i.cmd[0]<='9'){
                sscanf(i.cmd,"%d",&idx);
            }
            sscanf(i.c,"%c",&c);
            sscanf(i.num,"%d",&num);
            total+=num;
            if(idx>0){
                ins2(&root,idx,c,num);
            }else{
                if(!strcmp(i.cmd,"left")){
                    ins1(&root,c,0,num);
                }else{
                    ins1(&root,c,1,num);
                }
            }
        }else{
            int nn=0,cn=0;
            char last='\0';
            if(root){
                print(root,total,&last,&nn,&cn);             
            }
            fputs("$\n",stdout);
        }
        st=strtok(NULL," \n");
        cc++;
    }
    return 0;
}
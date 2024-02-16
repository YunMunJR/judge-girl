#include <stdio.h>
#include <string.h>
#include "evaluateTree.h"
int solve(Node* root,int* values){
    if(root->val[0]>='A'&&root->val[0]<='Z'){
        return values[(int)(root->val[0]-'A')];
    }else if(!strcmp(root->val,"!")){
        return !solve(root->left,values);
    }else{
        if(!strcmp(root->val,"||")){
            return solve(root->left,values)||solve(root->right,values);
        }else{
            return solve(root->left,values)&&solve(root->right,values);
        }
    }
}
void evaluateTree(Node *root, int *values){
#ifdef UPPER
    printf("%s\n",(solve(root,values)==1)?"TRUE":"FALSE");
#endif
#ifdef LOWER
    printf("%s\n",(solve(root,values)==1)?"true":"false");
#endif
}
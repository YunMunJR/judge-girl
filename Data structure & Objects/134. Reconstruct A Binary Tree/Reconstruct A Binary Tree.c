#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct data {
    int data;
    int level;
}data;
typedef struct treenode {
    int data;
    int level;
    struct treenode* left; 
    struct treenode* right;
}treenode;
treenode* gentreenode(treenode* left, treenode* right, int data, int level) {
    treenode* node = (treenode*)malloc(sizeof(treenode));
    node->data = data;
    node->level = level;
    node->left = left;
    node->right = right;
    return node;
}
treenode* findinsert(treenode* root, int data, int level) {
    if (!root){
        return gentreenode(NULL, NULL, data, level);
    }else {
        if (data > root->data){
            root->right = findinsert(root->right, data, level);
        }else{
            root->left = findinsert(root->left, data, level);
        }
    }
    return root;
}
void freetree(treenode* root) {
    if (!root){
        return;
    }else {
        freetree(root->left);
        freetree(root->right);
        free(root);
    }
}
int solve(int idx1, int idx2, data d[], treenode* root) {
    int distance = 0, count1 = 0, count2 = 0; treenode* ptr = root;
    data da1[1000], da2[1000], record;
    for (int i = 0; i < 1000; i++) {
        da1[i].data = 0; 
        da2[i].data = 0;
        da1[i].level = 0; 
        da2[i].level = 0;
    }
    while (ptr->data != d[idx1].data) {
        da1[count1].data = ptr->data; 
        da1[count1].level = ptr->level;
        if(ptr->data < d[idx1].data){ 
            count1++; 
            ptr = ptr->right; 
        }else{ 
            count1++; 
            ptr = ptr->left; 
        }
    }
    da1[count1].data = ptr->data; 
    da1[count1].level = ptr->level; 
    count1++;
    ptr = root;
    while (ptr->data != d[idx2].data) {
        da2[count2].data = ptr->data; 
        da2[count2].level = ptr->level;
        if (ptr->data < d[idx2].data){ 
            count2++; 
            ptr = ptr->right; 
        }else{ 
            count2++; 
            ptr = ptr->left; 
        }
    }
    da2[count2].data = ptr->data; 
    da2[count2].level = ptr->level; 
    count2++;
    for (int i = 0; da1[i].data == da2[i].data && da1[i].level == da2[i].level && da1[i].level != 0; i++){ 
        record = da1[i]; 
    }
    distance = (d[idx2].level - record.level) + (d[idx1].level - record.level);
    return distance;
}
int main(){
    int n, p, insertnum = 0, num1, num2, idx1, idx2; data d[1000]; treenode* root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &d[i].data, &d[i].level);
    }
    for (int i = 0; insertnum < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[j].level == i + 1){ 
                root = findinsert(root, d[j].data, d[j].level); 
                insertnum++;
            }
        }
    }
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        idx1 = 1001; idx2 = 1001;
        scanf("%d%d", &num1, &num2);
        for (int j = 0; idx1 > 1000 || idx2 >= 1000; j++) {
            if (d[j].data == num1){
                idx1 = j;
            }
            if (d[j].data == num2){
                idx2 = j;
            }
        }
        if ((d[idx1].data > root->data && d[idx2].data > root->data) || (d[idx1].data < root->data && d[idx2].data < root->data)){
            printf("%d", solve(idx1, idx2, d, root));
        }
        else{
            printf("%d", d[idx1].level + d[idx2].level - 2);
        }
        if (i != p - 1){
            putchar('\n');
        }
    }
    freetree(root);
}
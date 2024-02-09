#include "node.h"
#include <stdio.h>
void print(int path[], int pathlen) {
    for (int i = 0; i < pathlen; i++) {
        printf("%d ", path[i]);
    }
    putchar('\n');
}
void printpath(struct node* root, int path[], int pathlen) {
    if (!root){
        return;
    }
    path[pathlen] = root->data; pathlen++;
    if (!root->left && !root->right){
        print(path, pathlen);
    }else {
        printpath(root->left, path, pathlen);
        printpath(root->right, path, pathlen);
    }
}
void print_all_paths(struct node* root) {
    int path[1000], pathlen = 0;
    printpath(root, path, pathlen);
}
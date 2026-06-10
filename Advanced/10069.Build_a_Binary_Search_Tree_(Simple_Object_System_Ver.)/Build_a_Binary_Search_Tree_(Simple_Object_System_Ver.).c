#include <stdio.h>
#include <stdlib.h>

#include "node.h"

void dfsPrint(bstNode* u) {
    if (u == NULL)    return;
    u->print(u);
    dfsPrint(u->getLson(u));
    dfsPrint(u->getRson(u));
    FREE(bstNode, u);
}
void demo(bNode* u) {
    if (u == NULL)    return;
    u->print(u);
    demo(u->getLson(u));
    demo(u->getRson(u));
    FREE(bNode, u);
}

int main() {
   /*
    bNode* t, * u;
        t = NEW(bNode);
        u = NEW(bNode);
        //t->setLson(t, u);t->lson = u;thesame.
        
        //u->setRson(u, NEW(bNode));u->rson = NEW(bNode); the same.
        
        demo(t);*/
        
    int N;
     while (scanf_s("%d", &N) == 1 && N) {
        int* A = (int*)malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++)
            scanf_s("%d", &A[i]);
        bstNode* root = buildBST(A, N);
        
        dfsPrint(root);
        puts("");
        free(A);
    }
    return 0;
}
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
 
Node* mk_list(int n) {
    Node *head;
    // ...
    for (int i = 0; i < n; i++) {
        Node *u;
        // ...
        u->v = sp_rand(), u->next = NULL;
        // ...
    }
    return head;
}
void rm_list(Node *head) {
    // ...
}
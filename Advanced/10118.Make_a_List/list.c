#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
 
Node* mk_list(int n) {
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; i++) {
        Node *u;
        u = (Node*)malloc(sizeof(Node));
        u->v = sp_rand(), u->next = NULL;

        if (!head) {
            head = u;
            tail = u;
        } else {
            tail->next = u;
            tail = u;
        }
    }
    return head;
}
void rm_list(Node *head) {
    while(head){
        Node *next = head->next;
        free(head);
        head = next;
    }
}
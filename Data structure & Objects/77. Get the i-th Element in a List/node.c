#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node* getNode(struct node* head, unsigned int i) {
    struct node* tail = NULL, * head1 = head; i++;
    unsigned int count = 0, nodenum = 0;    
    assert(head1);
    while (head1) {
        if (!head1->next){
            tail = head1;
        }
        nodenum++; 
        head1 = head1->next;
    }
    head1 = head;
    if (i == 0){
        return head;
    }else {
        if (!i) {
            return tail;
        }else {
            while (head1 && count < nodenum - i) {
                count++; 
                head1 = head1->next;
            }
            return head1;
        }
    }
}
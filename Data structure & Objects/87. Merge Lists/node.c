#include "node.h"
#include <stdio.h>
struct node* merge(struct node* list1, struct node* list2) {
    struct  node* ptr1 = list1, * ptr2 = list2;
    struct  node* head = (list1->value < list2->value) ? list1 : list2, * ptr = head; int onlist1 = 0;
    if (ptr->value == ptr1->value){ 
        ptr1 = ptr1->next; 
        onlist1 = 1; 
    }else{ 
        ptr2 = ptr2->next; 
        onlist1 = 0; 
    }
    while (ptr1 && ptr2) {
        if (onlist1) {
            if (ptr1->value > ptr2->value) {
                ptr->next = ptr2; 
                ptr = ptr->next;
                ptr2 = ptr2->next; 
                onlist1 = 0;
            }else {
                ptr->next = ptr1; 
                ptr = ptr->next;
                ptr1 = ptr1->next;
            }
        }else {
            if (ptr1->value > ptr2->value) {
                ptr->next = ptr2; 
                ptr = ptr->next;
                ptr2 = ptr2->next; 
            }else {
                ptr->next = ptr1; 
                ptr = ptr->next;
                ptr1 = ptr1->next; 
                onlist1 = 1;
            }
        }
    }
    if (ptr1){
        ptr->next = ptr1;
    }else {
        ptr->next = ptr2;
    }
    return head;
}
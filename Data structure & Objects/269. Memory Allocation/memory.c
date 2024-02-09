#include "memory.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
Memory* getfreeblock(Memory* next, int start, int length) {
    Memory* node = (Memory*)malloc(sizeof(Memory));
    assert(node);
    node->start = start;
    node->length = length;
    node->next = next;
    return node;
}
 
void initMemory(Memory* memory, int length) {
    memory->next = getfreeblock(NULL, 0, length);
}
 
void printMemory(Memory* memory) {
    Memory* ptr = memory->next;
    fputs("==========\n",stdout);
    while (ptr) {      
        printf("start %d, length %d\n", ptr->start, ptr->length);
        ptr = ptr->next;
    }
}
 
void allocateMemory(Memory* memory, int start, int length) {
    Memory* current = memory->next, *before = NULL;
    int beginsame, endsame;   
    while (!((start >= current->start) && ((current->start + current->length) > start))) {
        before = current; 
        current = current->next; 
    }
    beginsame = (current->start == start);
    endsame = (current->start + current->length == start + length);
    if(beginsame && endsame) {
        if(!before) {
            memory->next = current->next;
        }else { 
            before->next = current->next;
        } 
        free(current);       
    }else if(beginsame) {
        current->start = start + length; 
        current->length -= length;
    }else if(endsame){
        current->length -= length;  
    }else{
        Memory* after = NULL; 
        after = getfreeblock(current->next, start + length, (current->start + current->length) - (start + length));
        current->next = after;
        current->length = start - current->start;
    }          
}
 
void freeMemory(Memory* memory, int start, int length) {
    Memory* current = memory->next, * before = NULL;
    while (current && start > current->start) {
        before = current; 
        current = current->next;
    }
    int adjacentbefore = before && (start == before->start + before->length);
    int adjacentcurrent = current && (start + length == current->start);
    if (adjacentcurrent && adjacentbefore) {
        before->length += (length + current->length);
        before->next = current->next;
        free(current);
    }else if(adjacentbefore){
        before->length += length;
    }else if (adjacentcurrent) {
        current->start -= length; 
        current->length += length;
    }else {
        Memory* between = getfreeblock(current, start, length);
        if (!before){
            memory->next = between;
        }
        else{
            before->next = between;
        }
    }          
}
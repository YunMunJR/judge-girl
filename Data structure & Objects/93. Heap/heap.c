#include "heap.h"
#include <stdint.h>
void initialize(struct Heap* heap){
    for (int i = 0; i < MAXHEAP; i++){
        heap->ary[i] = INT32_MAX;
    }
    heap->num = 0;
}
int removeMin(struct Heap* heap){
    int minidx = 0, min;
    for (int i = 1; i < 100; i++) {
        if (heap->ary[minidx] > heap->ary[i]){
            minidx = i;
        }
    }
    min = heap->ary[minidx]; 
    heap->ary[minidx] = INT32_MAX; 
    heap->num--;
    return min;
}
void add(struct Heap* heap, int i){
    for (int ii = 0; ii < 100; ii++) {
        if (heap->ary[ii] == INT32_MAX){ 
            heap->ary[ii] = i; 
            break; 
        }
    }
    heap->num++; 
}
int isFull(struct Heap* heap){
    if (heap->num >= MAXHEAP){
        return 1;
    }
    return 0;
}
int isEmpty(struct Heap* heap){
    if (!heap->num){
        return 1;
    }
    return 0;
}
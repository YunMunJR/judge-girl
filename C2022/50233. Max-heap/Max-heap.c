#include <stdio.h>
#include <assert.h>
int LEFT(int i) {
    return 2 * i;
}
int RIGHT(int i) {
    return 2 * i + 1;
}
int PARENT(int i) {
    return i / 2;
}
int GET_LARGEST(int A[], int i, int heapsize) {
    int l = LEFT(i), r = RIGHT(i), largest;
    if (l <= heapsize && A[l] > A[i]){
        largest = l;
    }else{
        largest = i;
    }
    if (r <= heapsize && A[r] > A[largest]){
        largest = r;
    }
    return largest;
}
void MAX_HEAPIFY(int A[], int i, int heapsize) {
    int largest = GET_LARGEST(A, i, heapsize), temp;
    while (largest != i) {
        temp = A[i]; 
        A[i] = A[largest]; 
        A[largest] = temp;
        i = largest; 
        largest = GET_LARGEST(A, i, heapsize);
    }
}
void BUILD_MAX_HEAP(int A[], int heapsize) {
    for (int i = heapsize / 2; i > 0; i--) {
        MAX_HEAPIFY(A, i, heapsize);
    }
}
void HEAP_EXTRACT_MAP(int A[], int heapsize) {
    assert(heapsize >= 1);
    int max = A[1]; printf("%d ", max); 
    A[1] = A[heapsize];
     heapsize--;
    MAX_HEAPIFY(A, 1, heapsize);
}
void MAX_HEAP_INSERT(int A[], int key, int heapsize) {
    heapsize++; 
    int i = heapsize, temp; 
    A[i] = key;
    while (i > 1 && A[PARENT(i)] < A[i]) {
        temp = A[i]; 
        A[i] = A[PARENT(i)]; 
        A[PARENT(i)] = temp;
        i = PARENT(i);
    }
}
int main() {
    static int heaparray[300001]; 
    int heapsize, operanum, operation;
    scanf("%d", &heapsize);
    for (int i = 1; i < heapsize + 1; i++){
        scanf("%d", &heaparray[i]);
    }
    BUILD_MAX_HEAP(heaparray, heapsize);
    scanf("%d", &operanum);
    for (int i = 1; i < heapsize + 1; i++) { 
        printf("%d", heaparray[i]); 
        if (i != heapsize){
            putchar(' '); 
        }else{
            putchar('\n');
        } 
    }
    for (int i = 0; i < operanum; i++) {
        scanf("%d", &operation);
        if (operation > 0) {
            MAX_HEAP_INSERT(heaparray, operation, heapsize);
            heapsize++;
        }
        else {
            HEAP_EXTRACT_MAP(heaparray, heapsize);
            heapsize--;
        }
    }
    return 0;
}
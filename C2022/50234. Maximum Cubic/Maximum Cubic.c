#define MAXN 100
#include <stdio.h>
#include <assert.h>
typedef struct cubic {
    int num, i, j, k;
}CUBIC;
void swap(int a, int b) {
    int temp; temp = a; a = b; b = temp;
}
int LEFT(int i) {
    return 2 * i;
}
int RIGHT(int i) {
    return 2 * i + 1;
}
int PARENT(int i) {
    return i / 2;
}
int GET_LARGEST(CUBIC A[], int i, int heapsize) {
    int l = LEFT(i), r = RIGHT(i), largest;
    if (l <= heapsize && A[l].num > A[i].num){
        largest = l;
    }else{
        largest = i;
    }
    if (r <= heapsize && A[r].num > A[largest].num){
        largest = r;
    }
    return largest;
}
void MAX_HEAPIFY( CUBIC A[], int i, int heapsize) {
    int largest = GET_LARGEST(A, i, heapsize), temp;
    while (largest != i) {
        temp = A[i].num; 
        A[i].num = A[largest].num; 
        A[largest].num = temp;
        temp = A[i].i; A[i].i = A[largest].i; A[largest].i = temp;
        temp = A[i].k; A[i].k = A[largest].k; A[largest].k = temp;
        temp = A[i].j; A[i].j = A[largest].j; A[largest].j = temp;
        i = largest; 
        largest = GET_LARGEST(A, i, heapsize);
    }
}
void BUILD_MAX_HEAP(CUBIC A[], int heapsize) {
    for (int i = heapsize / 2; i > 0; i--) {
        MAX_HEAPIFY(A, i, heapsize);
    }
}
void HEAP_EXTRACT_MAP(CUBIC A[], int heapsize) {
    assert(heapsize >= 1);
    int max = A[1].num; 
    printf("%d ", max); 
    A[1].num = A[heapsize].num; 
    A[1].i = A[heapsize].i; 
    A[1].j = A[heapsize].j; A[1].k = A[heapsize].k; 
    heapsize--;
    MAX_HEAPIFY(A, 1, heapsize);
}
void MAX_HEAP_INSERT(CUBIC A[], int key, int tempi,int tempj,int tempk,int heapsize) {
    heapsize++; 
    int i = heapsize, temp; A[i].num = key; 
    A[i].i = tempi; A[i].j = tempj;
    A[i].k = tempk;
    while (i > 1 && A[PARENT(i)].num < A[i].num) {
        temp = A[i].num; 
        A[i].num = A[PARENT(i)].num; 
        A[PARENT(i)].num = temp;
        temp = A[i].i; A[i].i = A[PARENT(i)].i; A[PARENT(i)].i = temp;
        temp = A[i].j; A[i].j = A[PARENT(i)].j; A[PARENT(i)].j = temp;
        temp = A[i].k; A[i].k = A[PARENT(i)].k; A[PARENT(i)].k = temp;
        i = PARENT(i);
    }
}
int main() {
    static CUBIC heaparray[MAXN * MAXN + 1], temp; 
    static int  cubic[MAXN + 1][MAXN + 1][MAXN + 1];
    int N;
    scanf("%d", &N); 
    int cubicnum = N * (N + 1) * (2 * N + 1) / 6 , heapsize = N * N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                scanf("%d", &cubic[i][j][k]);
                if (j == i || k == i) { 
                    heaparray[j * N + k + 1].num = cubic[i][j][k]; 
                    heaparray[j * N + k + 1].i = i;
                    heaparray[j * N + k + 1].j = j; 
                    heaparray[j * N + k + 1].k = k; 
                    cubic[i][j][k] = 0;
                }
            }
        }
    }
    BUILD_MAX_HEAP(heaparray, heapsize);
    while (cubicnum > 0) {
        temp.num = heaparray[1].num; 
        temp.i = heaparray[1].i; 
        temp.j = heaparray[1].j; 
        temp.k = heaparray[1].k;
        HEAP_EXTRACT_MAP(heaparray, heapsize); 
        heapsize--; 
        cubicnum--;
        cubic[temp.i][temp.j][temp.k] = 0;
        if (cubic[temp.i + 1][temp.j][temp.k] != 0) {
            MAX_HEAP_INSERT(heaparray, cubic[temp.i + 1][temp.j][temp.k],temp.i + 1, temp.j, temp.k, heapsize); 
            heapsize++;       
        }    
    }
    return 0;
}
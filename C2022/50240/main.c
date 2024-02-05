#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[101];
    int x;
    int y;
}heapdata;
int LEFT(int i) {
    return 2 * i;
}
int RIGHT(int i) {
    return 2 * i + 1;
}
int PARENT(int i) {
    return i / 2;
}
int GET_LARGEST(heapdata A[], int i, int heapsize) {
    int l = LEFT(i), r = RIGHT(i), largest;
    if (l <= heapsize && strcmp(A[l].s,A[i].s)>0)largest = l;
    else largest = i;
    if (r <= heapsize && strcmp(A[r].s,A[largest].s)>0)largest = r;
    return largest;
}
void MAX_HEAPIFY(heapdata A[], int i, int heapsize) {
    int largest = GET_LARGEST(A, i, heapsize);
    heapdata temp;
    while (largest != i) {
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        i = largest; largest = GET_LARGEST(A, i, heapsize);
    }
}
void BUILD_MAX_HEAP(heapdata A[], int heapsize) {
    for (int i = heapsize / 2; i > 0; i--) {
        MAX_HEAPIFY(A, i, heapsize);
    }
}
void HEAP_EXTRACT_MAP(heapdata A[], int heapsize) {
    assert(heapsize >= 1);
    printf("%s\n", A[1].s); 
    A[1]=A[heapsize];
    heapsize--;
    MAX_HEAPIFY(A, 1, heapsize);
}
void MAX_HEAP_INSERT(heapdata A[], char* key, int heapsize,int x,int y) {
    heapsize++; int i = heapsize; heapdata temp;
    strcpy(A[i].s,key);
    A[i].x=x;A[i].y=y;
    while (i > 1 && strcmp(A[PARENT(i)].s,A[i].s)<0) {
        temp=A[i];
        A[i]=A[PARENT(i)];
        A[PARENT(i)]=temp;
        i = PARENT(i);
    }
}
int main() {
    heapdata *heaparray; int heapsize=0, operanum, operation;
    char***tower,str[101];
    int n,m,**re,x,y;
    scanf("%d%d",&n,&m);
    heaparray=(heapdata*)malloc((n*n+1)*sizeof(heapdata));
    tower=(char***)malloc(m*sizeof(char**));
    re=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        re[i]=(int*)malloc(n*sizeof(int));        
    }
    for(int i=0;i<m;i++){
        tower[i]=(char**)malloc(n*sizeof(char*));
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            tower[i][j]=(char*)malloc(n*sizeof(char));
        }
    }
    for(int i=0;i<n;i++)memset(re[i],0,n*sizeof(int));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%s",tower[i][j]);
        }
    } 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tower[0][i][j]=='0'){
                re[i][j]++;
            }else{
                for(int k=0;tower[k][i][j]!='0';k++){
                    str[k]=tower[k][i][j];
                    re[i][j]++;
                }
                str[re[i][j]++]='\0';
                MAX_HEAP_INSERT(heaparray,str,heapsize,i,j);
                heapsize++;
            }
        }
    }  
    BUILD_MAX_HEAP(heaparray, heapsize);
    while(heapsize>0){
        x=heaparray[1].x;y=heaparray[1].y;
        HEAP_EXTRACT_MAP(heaparray, heapsize);heapsize--;
        if(re[x][y]<m){
            int start=re[x][y];
            for(int i=start;tower[i][x][y]!='0';i++){
                str[i-start]=tower[i][x][y];
                re[x][y]++;
            }           
            str[re[x][y]-start]='\0';
            re[x][y]++;
            MAX_HEAP_INSERT(heaparray,str,heapsize,x,y);
            heapsize++;
        }
    }
    free(heaparray);
    for(int i=0;i<n;i++){
        free(re[i]);
    }
    free(re);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            free(tower[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        free(tower[i]);
    }
    free(tower);
    return 0;
}
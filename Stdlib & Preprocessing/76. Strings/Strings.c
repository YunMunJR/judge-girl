#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void*b){
    return strcmp(*(const char**)a,*(const char**)b);
}
int main(){
    char str[70][35],*strptr[70],s[35];
    int c=0,cc=0;
    while(fgets(str[c],35,stdin)!=NULL){
        strptr[c]=str[c];
        c++; 
    }
    qsort(strptr,c,sizeof(char*),cmp);
    for(int i=0;i<c;i++){
        fputs(strptr[i],stdout);
    }
    return 0;
}
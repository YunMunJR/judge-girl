#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char* s[126000];
    char* ptr[126000];
    int num;
}data;
int cmp(const void*a,const void*b){
    return (strcmp(*(char**)a,*(char**)b));
}
int main(){
    data d;
    char s[501],*ptr;
    ptr=s;
    d.num=0;
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        for(int j=1;j<=len-i;j++){
            char ss[500][501];
            int find=0;
            d.s[d.num]=(char*)malloc(501*sizeof(char));
            strncpy(d.s[d.num],ptr,j);
            d.ptr[d.num]=d.s[d.num];  
            if(d.num>300){
                for(int ii=0;ii<300;ii++){
                    if(!strcmp(d.s[ii],d.s[d.num])){
                        find=1;
                        break;
                    }
                }
            }
            if(!find){ 
                d.num++;
            }else{
                free(d.s[d.num]);
            }   
        }
        ptr++;
    }
    qsort(d.ptr,d.num,sizeof(char*),cmp);
    printf("%s\r\n",d.ptr[0]);
    for(int i=1;i<d.num;i++){
        if(strcmp(d.ptr[i],d.ptr[i-1])!=0){
            printf("%s\r\n",d.ptr[i]);
        }
    }
    return 0;
}
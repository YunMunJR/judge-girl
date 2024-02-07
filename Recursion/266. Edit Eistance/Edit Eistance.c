#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
typedef struct{
    int s1;
    int s2;
    int d;
}strmax;
int min(int a,int b){
    return (a<b)?a:b;
}
int solve(char* s1,char* s2,int s1len,int s2len){
    if(*s1=='\0'||*s2=='\0'){
        if(*s1=='\0'){      
            return s2len-s1len;
        }else{
            return s1len-s2len;
        }
    }else{
        if(*s1==*s2){
            return solve(s1+1,s2+1,s1len-1,s2len-1);
        }else{
            return 1+min(solve(s1+1,s2,s1len-1,s2len),solve(s1,s2+1,s1len,s2len-1));
        }
    }
}
int main(){
    char s[100][15];
    strmax m;
    for(int i=0;i<100;i++){
        memset(s[i],0,15);
    }
    int c=0;
    while(scanf("%s",s[c])!=EOF){
        c++;
    }
    m.d=INT32_MAX;
    for(int i=0;i<c-1;i++){
        for(int j=i+1;j<c;j++){
            int d=solve(s[i],s[j],strlen(s[i]),strlen(s[j]));
            if(d<m.d){
                m.d=d;
                m.s1=i+1,
                m.s2=j+1;
            }
        }
    }
    printf("%d %d %d",m.d,m.s1,m.s2);
    return 0;
}
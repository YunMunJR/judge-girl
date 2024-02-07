#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[3][10];
    char ss[3][10];
}data;
int expo(int base,int exp){
    int re=1;
    for(int i=0;i<exp;i++){
        re*=base;
    }
    return re;
}
void solve(data*d,int a[],int record[],int c,int count){
    if(count>=expo(9,c)){
        return;
    }
    if(a[record[0]]>=10){
        for(int i=0;i<c-1;i++){
            if(a[record[i]]>=10){
                a[record[i]]=1;
                a[record[i+1]]++;
            }else{
                break;
            }
        }
    }         
        for(int i=0;i<3;i++){
            strcpy(d->ss[i],d->s[i]);
            for(int j=0;j<strlen(d->ss[i]);j++){
                if(isupper(d->s[i][j])){
                    for(int ii=0;ii<c;ii++){
                        if(d->ss[i][j]==(char)((int)('A')+record[ii])){
                            d->ss[i][j]=(char)((int)('0')+a[record[ii]]);
                            break;
                        }
                    }
                }  
            }   
        }
        int n1=atoi(d->ss[0]),n2=atoi(d->ss[1]),mul=atoi(d->ss[2]);
        if(n1*n2==mul){
            printf("%d x %d = %d\n",n1,n2,mul);
            return;
        }else{
            a[record[0]]++;
            solve(d,a,record,c,count+1);
        }
} 
int main(){
    data d;
    int a[26]={0},record[26],c=0;
    scanf("%s",d.s[0]);
    scanf("%s",d.s[1]);
    scanf("%s",d.s[2]);
    for(int i=0;i<3;i++){
        for(int j=0;j<strlen(d.s[i]);j++){
            if(isupper(d.s[i][j])){
                a[d.s[i][j]-'A']++;
            }
        }
    }
    for(int i=0;i<26;i++){
        if(a[i]>0){
            a[i]=1;
            record[c]=i;
            c++;
        }
    }
    solve(&d,a,record,c,0);
}
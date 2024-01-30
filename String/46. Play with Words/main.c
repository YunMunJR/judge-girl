#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char cmd[5];
    char c[2];
}insert;
typedef struct{
    char cmd[5];
}delete;
int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
    char cmd[10];
    int n=0;
    int a[26];
    char s[50000],s2[50000],s3[50000];
    memset(s,0,50000);
    memset(s2,0,50000);
    memset(s3,0,50000);
    insert i;
    delete d; 
    for(int i=0;i<26;i++)a[i]=0;   
    while(scanf("%s",cmd)!=EOF){   
        if(!strcmp(cmd,"insert")){
            scanf("%s",i.cmd);
            i.cmd[strlen(i.cmd)]='\0';
            scanf("%s",i.c); 
            if(i.cmd[0]>='a'&&i.cmd[0]<='z'){
                if(!strcmp(i.cmd,"left")){
                    sprintf(s3,"%s%s",i.c,s);
                    strcpy(s,s3);        
                }
                else {
                    sprintf(s3,"%s%s",s,i.c);
                    strcpy(s,s3);             
                }
            }      
            else{
                int n,len=strlen(s);
                sscanf(i.cmd,"%d",&n);
                for(int i=0;i<n-1;i++){
                    s2[i]=s[i];
                }
                s2[n-1]=i.c[0];
                for(int i=n-1;i<len;i++){
                    s2[i+1]=s[i];
                }
                s2[len+1]='\0';
                strcpy(s,s2);
            }
        }
        else{
            int len=strlen(s);
            char c;
            scanf("%s",d.cmd);
            if(d.cmd[0]>='a'&&d.cmd[0]<='z'){
                if(!strcmp(d.cmd,"left")){
                    sscanf(s,"%c%s",&c,s3);
                    for(int i=1;i<len;i++){
                        s3[i-1]=s[i];
                    }
                    s3[len-1]='\0';
                    strcpy(s,s3);
                }
                else{
                    s[len-1]='\0';
                }
            }       
            else{
                int n;
                sscanf(d.cmd,"%d",&n);
                for(int i=0;i<n-1;i++){
                    s2[i]=s[i];
                }
                for(int i=n;i<len;i++){
                    s2[i-1]=s[i];
                }
                s2[len-1]='\0';
                strcpy(s,s2);
            }
        }
    }
    fprintf(stderr,"%s\n",s);
    n=1;
    int len=strlen(s),maxx=0;
    for(int i=1;i<len;i++){
        if(s[i]==s[i-1]){
            n++;
        }
        else{          
            a[(int)s[i-1]-'a']=max(a[(int)s[i-1]-'a'],n);
            n=1;
        }
    }
    a[(int)s[len-1]-'a']=max(a[(int)s[len-1]-'a'],n);
    for(int i=0;i<26;i++){
        maxx=max(maxx,a[i]);
    }
    n=1;
    if(len>1){
        for(int i=1;i<len;i++){
            if(s[i]==s[i-1]){
                n++;
            }
            else{
                if(maxx==n){
                    printf("%c ",s[i-1]);
                }
                n=1;
            }
        }
        if(maxx==n)printf("%c ",s[len-1]);
    }
    else if(len==1)printf("%c ",s[0]);
    printf("%d",maxx);
    return 0;
}
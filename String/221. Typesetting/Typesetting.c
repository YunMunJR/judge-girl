#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char s[128][256];
    int c=0,cc=0,r,ra;
    int totallen,len=0,slen;
    unsigned long long start=0,end=0; 
    scanf("%d",&totallen);
    char *buf,*st,ch;
    buf=(char*)malloc(10000000*sizeof(char));
    scanf("%c",&ch);
    fread(buf,1,10000000,stdin);
    st=strtok(buf," \n");
    while(st){
        strcpy(s[cc%128],st);
        slen=(strlen(s[cc%128])+1);
        len+=slen;
        if(len>totallen+1){
            len-=slen;
            end=cc;
            r=totallen-len;
            r+=(end-start);
            if(end-start-1!=0){
                ra=r/(end-start-1);    
            } 
            r-=(ra*(end-start-1));
            for(int i=start;i<end-1;i++){     
                printf("%s",s[i%128]);
                if(i-start<r){
                    printf(" ");
                }
                for(int i=0;i<ra;i++){
                    printf(" ");       
                }    
            }         
            printf("%s",s[(end-1)%128]);
            if(start==end-1){
                for(int i=0;i<totallen-len+(end-start);i++){
                    printf(" ");
                }    
            }
            printf("\n");
            len=slen;
            start=cc;
        }
        cc++;
        st=strtok(NULL," \n");
    }
    end=cc;
    r=totallen-len;
    r+=(end-start);
    if(end-start-1!=0){
        ra=r/(end-start-1); 
    }    
    r-=(ra*(end-start-1));
    for(int i=start;i<end-1;i++){     
        printf("%s",s[i%128]);
        if(i-start<r){
            printf(" ");
        }
        for(int i=0;i<ra;i++){
            printf(" ");       
        }    
    }
    printf("%s",s[(end-1)%128]);
    if(start==end-1){
        for(int i=0;i<totallen-len+(end-start);i++){
            printf(" ");
        }    
    }
    printf("\n");
    free(buf);
    return 0;
}
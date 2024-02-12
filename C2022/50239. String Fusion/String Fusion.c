#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char s[2001],str[51];
    memset(s,0,2001);
    int maxlen,strnum,pos;
    scanf("%d%d",&maxlen,&strnum);
    for(int i=0;i<strnum;i++){
        scanf("%s",str);
        scanf("%d",&pos);
        int len=strlen(str);
        for(int j=pos;j<pos+len;j++){
            if(s[j]=='\0'){
                s[j]=str[j-pos];
            }else{
                s[j]=(float)(((int)s[j]+(int)str[j-pos])/2);
            }
        }
    }
    int findalpha=0;
    for(int i=2000;i>=0;i--){
        if(!findalpha){
            (s[i]>='a'&&s[i]<='z')&&(findalpha=1);
        }else{
            (s[i]=='\0')&&(s[i]=' ');
        }
    }
    printf("%s",s);
    return 0;
}
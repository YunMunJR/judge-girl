#include <stdbool.h>
#include <stdio.h>
int main(){
    int sentence=0;
    int sentencenum=0,spacenum=0;
    char ch;
    while(scanf("%c",&ch,1)!=EOF){
        if (sentence){
            if (ch == '\n' && spacenum == 0){
                sentencenum++; 
                sentence = 0;
            }else if (ch == '\0'){
                sentencenum++; 
                sentence = 0;
            }else if (ch == ' ' && spacenum == 0){
                spacenum++;
            }else if (ch == ' ' && spacenum == 1){
                sentencenum++; 
                spacenum = 0; 
                sentence = 0;
            }else if (ch == '.'){
                spacenum = 0; 
            }else{
                spacenum = 0; 
                sentence = 0;
            }
        }else{
            if (ch == '.'){
                sentence = 1;
            }            
        }
    }
    printf("%d", sentencenum);
    return 0;
}
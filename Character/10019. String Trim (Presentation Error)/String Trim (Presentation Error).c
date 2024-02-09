#include <stdio.h>
#include <ctype.h>
int main(){
    char string[101]={'\0'}, ch;
    int i = 0,t=0;
    while (scanf("%c", &ch,1) != EOF ){
        if (ch != '\n'){
            string[i] = ch; 
            i++;
        }
        else{
            break;
        }      
    }
    for (int j = 0; j < i; j++){
        int k = isspace(string[j]);
        if (k!=0){
            string[j]='\0'; 
        }
        else{
            break;
        }       
    }
    for (int j = i-1; j >=0; j--){
        int k = isspace(string[j]);
        if (k != 0){
            string[j] = '\0';
        }
        else{
            break;
        }      
    }
    for (int j = 0; j < i; j++){
        if (string[j] != '\0'){
            printf("%c",string[j]);
        }
    }
    return 0;
}
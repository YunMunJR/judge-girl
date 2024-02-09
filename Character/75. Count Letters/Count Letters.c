#include <stdio.h> 
int main(){
    char q;
    int i = 0, a[26] = {0};
    while (scanf("%c",&q) != EOF){    
        switch (q){
            case 'a': case'A':
                a[0]++; 
                break;
            case 'b': case'B':
                a[1]++; 
                break;
            case 'c': case'C':
                a[2]++; 
                break;
            case 'd': case'D':
                a[3]++; 
                break;
            case 'e': case'E':
                a[4]++; 
                break;
            case 'f': case'F':
                a[5]++; 
                break;
            case 'g': case'G':
                a[6]++; 
                break;
            case 'h': case'H':
                a[7]++; 
                break;
            case 'i': case'I':
                a[8]++; 
                break;
            case 'j': case'J':
                a[9]++; 
                break;
            case 'k': case'K':
                a[10]++; 
                break;
            case 'l': case'L':
                a[11]++; 
                break;
            case 'm': case'M':
                a[12]++; 
                break;
            case 'n': case'N':
                a[13]++; 
                break;
            case 'o': case'O':
                a[14]++; 
                break;
            case 'p': case'P':
                a[15]++; 
                break;
            case 'q': case'Q':
                a[16]++; 
                break;
            case 'r': case'R':
                a[17]++; 
                break;
            case 's': case'S':
                a[18]++; 
                break;
            case 't': case'T':
                a[19]++; 
                break;
            case 'u': case'U':
                a[20]++; 
                break;
            case 'v': case'V':
                a[21]++; 
                break;
            case 'w': case'W':
                a[22]++; 
                break;
            case 'x': case'X':
                a[23]++; 
                break;
            case 'y': case'Y':
                a[24]++; 
                break;
            case 'z': case'Z':
                a[25]++; break;
            default:
                break;
            }   
        i++;
    }
    for (int j = 0; j < 26; j++){
        if (j != 25){
            printf("%d\n", a[j]);
        }else{
            printf("%d", a[j]);
        }       
    }
    return 0;
}
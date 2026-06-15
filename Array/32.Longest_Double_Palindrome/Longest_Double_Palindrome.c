#include <stdio.h>
#include <stdbool.h>
int palindrome_length(int t1, int i1, int arr[100]){
    int length = 0, symmetry = 1;
    for (int i = i1; i < t1; i++){
        for (int j = i1; j <= (i + i1) / 2; j++){
            if (i == i1){
                if (arr[j] == 1 || arr[j] == 2 || arr[j] == 3 || arr[j] == 4 || arr[j] == 5 || arr[j] == 6 || arr[j] == 7 || arr[j] == 8 || arr[j] == 9){
                    length = 1;
                }else{
                    symmetry = 0;
                    break;
                }
            }else{
                if (t1 > 2){
                    if (arr[j] != arr[i + i1 - j]){
                        symmetry = 0;
                        break;
                    }
                }
                else{
                    break;
                }       
            }
        }
        if (t1 > 2){
            if (symmetry){
                length = i - i1 + 1;
            }else{
                symmetry = 1;
            }
        }
        else{
            break;
        }     
    }
    return length;
}
int palindrome_length2(int t1, int i1, int arr[100]){
    int length = 0,i = t1-1, symmetry = 1;
    for (int j = i1; j <= (i+t1)/2; j++){
        if (i1 == t1-1&&length==0){
            if (arr[j] == 1|| arr[j] == 2|| arr[j] == 3|| arr[j] == 4|| arr[j] == 5|| arr[j] == 6|| arr[j] == 7|| arr[j] == 8|| arr[j] == 9){
                length = 1;
            }else{
                symmetry = 0;
                break;
            }
        }else{
            if (arr[j] != arr[i + i1 - j]){
                symmetry = 0;
                break;
            }
        }
    }
    if (symmetry){
        length = i - i1 + 1;
    }else{
        symmetry = 1;
    }
    return length;
}
int main(void){
    int digit, a[100] = {0},t=0,length[50]={0};
    int i = 0, num=0, doublepalindrome = 0,firstpoint=0; 
    while (scanf("%d", &digit) != EOF){
        a[t] = digit;
        t++;
    }
    for (int i = 0; i < t; i++){
        if (palindrome_length(t, i, a) != 0){
            for (int j = 0; j < i; j++){
                if (palindrome_length2(i, j, a) != 0){
                    if (doublepalindrome <= palindrome_length(t, i, a) + palindrome_length2(i, j, a)){        
                        if (i - palindrome_length2(i, j, a) > firstpoint&& doublepalindrome== palindrome_length(t, i, a) + palindrome_length2(i, j, a)){
                            num = j; 
                            firstpoint = i - palindrome_length2(i, j, a);
                        }else if (doublepalindrome < palindrome_length(t, i, a) + palindrome_length2(i, j, a)){
                            num = j; 
                            firstpoint = i - palindrome_length2(i, j, a);        
                            doublepalindrome = palindrome_length(t, i, a) + palindrome_length2(i, j, a);      
                        }
                    }
                }
            }
        }
    }
    if (doublepalindrome != 0){
        for (int i = num; i < num + doublepalindrome; i++){
            if (i != num + doublepalindrome - 1){
                printf("%d ", a[i]);
            }else{
                printf("%d", a[i]);
            }      
        }
    }
    return 0;
}
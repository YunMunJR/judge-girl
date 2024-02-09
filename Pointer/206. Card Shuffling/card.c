#include "card.h"
#include <stddef.h>
#include <stdio.h>
void shuffle(int* deck[]) {
    int index=0;
    while (deck[index]){
        index++;
    }   
    int a[5000];
    if (index % 2){
        for (int i = 0; i < index / 2; i++){
            a[i] = *deck[index - (index / 2) + i]; 
        }   
        for (int i = index - (index/ 2) - 1; i >= 0; i--){
            *deck[2*i] = *deck[i];
        }    
        for (int i = 0; i < index / 2; i++){
            *deck[2 * i + 1] = a[i];
        }      
    }else{
        for (int i = 0; i < index / 2; i++){
            a[i] = *deck[index - (index / 2) + i];
        }   
        for (int i = index-(index/2)-1; i>=0; i--){
            *deck[2*i] = *deck[i];
        }   
        for (int i = 0; i < index / 2; i++){
            *deck[2 * i + 1] = a[i];
        }     
    }
}
void print(int* deck[]) {
    int index = 0;
    while (deck[index]){
        index++;
    }   
    for (int i = 0; i < index; i++){
        printf("%d ", *deck[i]);
    }
}
#include "evaluate_f.h" 
int evaluate_f(int *iptr[], int n, int *index){
    int maxvalue=0;
    *index = 0;   
    for(int i=0;i<n;i++) {
        if(!i){
            maxvalue=(*iptr[i])*4-(*(iptr[i]+1))*6;                     
        }else{            
            if(maxvalue<(*iptr[i])*4-(*(iptr[i]+1))*6){
                maxvalue=(*iptr[i])*4-(*(iptr[i]+1))*6; 
                *index = i;
            }
        }
    }
   return maxvalue; 
} 
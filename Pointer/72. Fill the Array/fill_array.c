#include "fill_array.h"
void fill_array(int *ptr[], int n){
    int i=1,j=1,size=(ptr[n-1]-ptr[0])+1,a[n],t=0; 
    for(int k=0;k<size;k++){
        *(ptr[0]+k)=-1;
    }
    for(int k=0;k<n;k++){
        *ptr[k]=k;
    }
    for(int m=0;m<size;m++){
        if(*(ptr[0]+m)!=-1){
            a[t]=*(ptr[0]+m);
            t++;
        }
    }    
    while(i<n&&j<size){
        if(*(ptr[0]+j)!=a[i]){
            *(ptr[0]+j)=a[i-1]+a[i];
            j++;
        }else{
            i++;
            j++;
        }
    }
} 
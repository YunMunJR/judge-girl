#include "snake.h"
void snake(const int *ptr_array[100][100], int m){
    int min=0,max=0;
    int*a[m*m];
    int* temp;
    int t=-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++)
        a[i*m+j]=ptr_array[i][j];
    }
    for(int i1=0;i1<m;i1++){
        if(i1%2==0){
            for(int j1=0;j1<m;j1++){
                for(int i=0;i<m*m;i++){
                    min=*ptr_array[i1][j1];
                    if(min>(*a[i])&&(*a[i])>=0){ 
                        temp=ptr_array[i1][j1];
                        ptr_array[i1][j1]=ptr_array[(i-i%m)/m][i%m];
                        ptr_array[(i-i%m)/m][i%m]=temp;
                        temp=a[i];
                        a[i]=a[i1*m+j1];
                        a[i1*m+j1]=temp;                          
                    }
                }
                a[i1*m+j1]=&t;
            }    
        }else{
            for(int j1=m-1;j1>=0;j1--){
                for(int i=0;i<m*m;i++){
                    min=*ptr_array[i1][j1];
                    if(min>*a[i]&&*a[i]>=0){ 
                        temp=ptr_array[i1][j1];
                        ptr_array[i1][j1]=ptr_array[(i-i%m)/m][i%m];
                        ptr_array[(i-i%m)/m][i%m]=temp;
                        temp=a[i];
                        a[i]=a[i1*m+j1];
                        a[i1*m+j1]=temp;                 
                    }
                }
                a[i1*m+j1]=&t;
            }    
        }
    }
}
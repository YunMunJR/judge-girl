#include <stdio.h>
void sparseMatrixMult(int** A, int** B){
    int sum=0;
    for(int i=0;A[i]!=NULL;i++){
        sum=0;
        for(int ii=0;B[ii]!=NULL;ii++){
            sum=0;
            for(int j=1;A[i][j]!=-1;j+=2){   
                for(int jj=1;B[ii][jj]!=-1;jj+=2){     
                    if(A[i][j]==B[ii][jj]){
                        sum+=(A[i][j+1]*B[ii][jj+1]);
                        break;
                    }else if(A[i][j]<B[ii][jj]){
                        break;
                    }
                }
            }
            if(sum!=0){
                printf("%d %d %d\n",A[i][0],B[ii][0],sum);
            }
        }
    }
}
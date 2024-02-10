#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n,i,j,m,n0=0,n1=0,n2=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        m=a[i]%3;
        switch (m) {
            case 0:
                n0++; 
                break;
            case 1:
                n1++;
                break;
            case 2:
                n2++;
                break;    
        }
    }
    printf("%d %d %d",n0,n1,n2);
    return 0;
}
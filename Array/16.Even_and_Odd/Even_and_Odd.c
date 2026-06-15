#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n,i,o=0,e=0;
    scanf("%d",&n);
    int a[n],even[n],odd[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);    
    }
    for(i=0;i<n;i++){
        if(a[i]%2==0){
            even[e]=a[i];
            e++;    
        }else{
            odd[o]=a[i];
            o++;
        }        
    }
    for(i=0;i<o;i++){
        if(i!=o-1){
            printf("%d ",odd[i]);
        }else{
            printf("%d\n",odd[i]);
        }
    }
    for(i=0;i<e;i++){
        if(i!=e-1){
            printf("%d ",even[i]);
        }else{
            printf("%d\n",even[i]);
        }
    }
    return 0;
}
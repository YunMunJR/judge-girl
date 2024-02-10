#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
   long long ldx;
   long long ldy;
   long long rux;
   long long ruy;
}rectangle; 
int minldx_(rectangle array1[1],rectangle array2[1]){
    int minldx;
    minldx=(array1[0].ldx<array2[0].ldx)? array1[0].ldx:array2[0].ldx;
    return minldx;
}
int minldy_(rectangle array1[1],rectangle array2[1] ){
    int minldy;
    minldy=(array1[0].ldy>array2[0].ldy)? array2[0].ldy:array1[0].ldy;
    return minldy;
}
int maxrux_(rectangle array1[1],rectangle array2[1] ){
    int maxrux;
    maxrux=(array1[0].rux>array2[0].rux)? array1[0].rux:array2[0].rux;
    return maxrux;
}
int maxruy_(rectangle array1[1],rectangle array2[1] ){
    int maxruy;
    maxruy=(array1[0].ruy>array2[0].ruy)? array1[0].ruy:array2[0].ruy;
    return maxruy;
}
int overlap2(rectangle array1[1],rectangle array2[1]){
    int i,j;
    long long x1,y1,x2,y2,minldx,minldy,maxrux,maxruy,numx,numy;
    numx=0;numy=0;
    minldx=minldx_(array1,array2);
    minldy=minldy_(array1,array2);
    maxrux=maxrux_(array1,array2);
    maxruy=maxruy_(array1,array2);
    x1=array1[0].ldx-array2[0].ldx;
    x2=array1[0].rux-array2[0].rux;
    y1=array1[0].ldy-array2[0].ldy;
    y2=array1[0].ruy-array2[0].ruy;
    if(llabs(x1)<=20000&&llabs(x2)<=20000&&llabs(y1)<=20000&&llabs(y2)<=20000){
        for(i=minldx;i<=maxrux;i++){
            if(i>=array1[0].ldx&&i>=array2[0].ldx&&i<=array1[0].rux&&i<=array2[0].rux){
                numx++;
            }
            if(i==maxrux){
                break;
            }    
        }
        for(i=minldy;i<=maxruy;i++){
            if(i>=array1[0].ldy&&i>=array2[0].ldy&&i<=array1[0].ruy&&i<=array2[0].ruy){
                numy++;
            }
            if(i==maxruy){
                break;
            }    
        }
        if(numx>0&&numy>0){
            return (numx-1)*(numy-1);
        }else{
            return 0;
        }
    }else{
        return 0;
    }   
}
int minildx(rectangle array1[1],int n){
    int t;
    t=(array1[0].ldx>n)?n:array1[0].ldx;
    return t;
}
int minildy(rectangle array1[1],int n){
    int t;
    t=(array1[0].ldy>n)?n:array1[0].ldy;
    return t;
}
int maxirux(rectangle array1[1],int n){
    int t;
    t=(array1[0].rux<n)?n:array1[0].rux;
    return t;
}
int maxiruy(rectangle array1[1],int n){
    int t;
    t=(array1[0].ruy<n)?n:array1[0].ruy;
    return t;
}
int overlap3(rectangle array1[1],rectangle array2[1],rectangle array3[1]){
    int minldx,minldy,maxrux,maxruy,numx,numy,i,j;
    numx=0;numy=0;
    minldx=minildx(array3,minldx_(array1,array2));
    minldy=minildy(array3,minldy_(array1,array2));
    maxrux=maxirux(array1,maxrux_(array1,array2));
    maxruy=maxiruy(array1,maxruy_(array1,array2));
    if(overlap2(array1,array2)!=0&&overlap2(array2,array3)!=0&&overlap2(array3,array1)!=0){
        for(i=minldx;i<=maxrux;i++){
            if(i>=array1[0].ldx&&i>=array2[0].ldx&&i>=array3[0].ldx&&i<=array1[0].rux&&i<=array2[0].rux&&i<=array3[0].rux){
                numx++;
            }
        }
        for(i=minldy;i<=maxruy;i++){
            if(i>=array1[0].ldy&&i>=array2[0].ldy&&i>=array3[0].ldy&&i<=array1[0].ruy&&i<=array2[0].ruy&&i<=array3[0].ruy){
                numy++;
            }
        }
        if(numx>0&&numy>0){
            return (numx-1)*(numy-1);
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}
int main(int argc, char *argv[]) {    
    rectangle a[1],b[1],c[1];
    int i,j,n1,n2,n3,n4,area;
    area=0;n1=0;n2=0;n3=0;n4=0;
        scanf("%lld%lld%lld%lld",&a[0].ldx,&a[0].ldy,&a[0].rux,&a[0].ruy);
        area+=(a[0].rux-a[0].ldx)*(a[0].ruy-a[0].ldy);
        scanf("%lld%lld%lld%lld",&b[0].ldx,&b[0].ldy,&b[0].rux,&b[0].ruy);
        area+=(b[0].rux-b[0].ldx)*(b[0].ruy-b[0].ldy);
        scanf("%lld%lld%lld%lld",&c[0].ldx,&c[0].ldy,&c[0].rux,&c[0].ruy);
        area+=(c[0].rux-c[0].ldx)*(c[0].ruy-c[0].ldy);
        n1=overlap2(a,b);
        n2=overlap2(b,c);
        n3=overlap2(a,c);
        n4=overlap3(a,b,c);
        printf("%d",area-n1-n2-n3+n4);
    return 0;
}
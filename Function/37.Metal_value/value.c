#include <stdio.h> 
int gcd(int x,int y){    
    int n=1;
    while(n!=0){
        n=x%y;
        x=y;
        y=n;
    }
    return x;
}
int valu(int type){
    int val=0;
        switch(type){
            case 79:
                val=30;
                break;
            case 47:
                val=10;
                break;    
            case 29:
                val=4;
                break;
            case 82:
                val=5;
                break;
            case 26:
                val=3;
                break;
            case 22:
                val=9;
                break;
            default:
                break; 
        }
    return val;    
}
int value(int type, int width, int height, int length){
    int Gcd,price;
    price=valu(type);
    Gcd=gcd(width,gcd(height,length));
    if(type!=79&&type!=47&&type!=29&&type!=82&&type!=26&&type!=22){
        return -1;
    }else{
        if(!(width>0&&height>0&&length>0)){
            return -2;
        }else{
            return Gcd*Gcd*Gcd*width*height*length*price;
        }
    }    
}
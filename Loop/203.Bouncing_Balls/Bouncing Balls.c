#include <stdio.h>
typedef struct coor {
    int x, y;
}coor;
int main(){
    int X, Y,sec,i=0;
    coor ball1, ball2, d_ball1, d_ball2;
    scanf("%d%d%d%d%d%d%d%d%d%d%d", &X, &Y, &ball1.x, &ball1.y, &ball2.x, &ball2.y, &d_ball1.x, &d_ball1.y, &d_ball2.x, &d_ball2.y,&sec);
    int k1, k2,k3;
    for (i=0;i<sec;i++){
        int tem;
        ball1.x += d_ball1.x;
        ball1.y += d_ball1.y;
        ball2.x += d_ball2.x;
        ball2.y += d_ball2.y;
        k1 = ((ball1.x == 1 || ball1.x == X) && (ball1.y == 1 || ball1.y == Y));
        k2 = ((ball2.x == 1 || ball2.x == X) && (ball2.y == 1 || ball2.y == Y));
        k3 = (ball2.x == 1 || ball2.x == X||ball2.y == 1 || ball2.y == Y);
        if (ball1.x != ball2.x || ball1.y != ball2.y){
            if (ball1.x == X || ball1.x == 1){
                if (k1){
                    d_ball1.x = -d_ball1.x;
                    d_ball1.y = -d_ball1.y;
                }else{
                    d_ball1.x = -d_ball1.x;
                }     
            }
            if (ball1.y == Y || ball1.y == 1){
                if(!k1){
                    d_ball1.y = -d_ball1.y;
                } 
            }
            if (ball2.x == X || ball2.x == 1){
                if (k2){
                    d_ball2.x = -d_ball2.x;
                    d_ball2.y = -d_ball2.y;
                }
                else{
                    d_ball2.x = -d_ball2.x;
                }      
            }
            if (ball2.y == Y || ball2.y == 1){
                if(!k2){
                    d_ball2.y = -d_ball2.y;
                }   
            }
        }else{
            if (k3){
                if ((ball2.x == X || ball2.x == 1)){
                    d_ball1.x = -d_ball1.x;
                    d_ball2.x = -d_ball2.x;
                    tem = d_ball1.x;
                    d_ball1.x = d_ball2.x;
                    d_ball2.x = tem;
                    tem = d_ball1.y;
                    d_ball1.y = d_ball2.y;
                    d_ball2.y = tem;
                }else{
                    d_ball1.y = -d_ball1.y;
                    d_ball2.y = -d_ball2.y;
                    tem = d_ball1.x;
                    d_ball1.x = d_ball2.x;
                    d_ball2.x = tem;
                    tem = d_ball1.y;
                    d_ball1.y = d_ball2.y;
                    d_ball2.y = tem;
                }
            }else{
                tem = d_ball1.x;
                d_ball1.x = d_ball2.x;
                d_ball2.x = tem;
                tem = d_ball1.y;
                d_ball1.y = d_ball2.y;
                d_ball2.y = tem;
            }
        }
    }
    printf("%d\n%d\n%d\n%d", ball1.x, ball1.y, ball2.x, ball2.y);
    return 0;
}
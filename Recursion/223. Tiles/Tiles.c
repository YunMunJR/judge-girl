#include <stdio.h>
#include <stdlib.h>
void tile1(int l, int m, int x, int y);
void tile2(int l, int m, int x, int y);
void tile3(int l, int m, int x, int y);
void tile4(int l, int m, int x, int y);
void tile1(int l, int m, int x, int y) {
    if (l == 2 || m == 1){
        printf("1 %d %d\n", x, y); return;
    }else{
        tile1(l / 2, m / 2, x, y);
        tile4(l / 2, m / 2, x-(m/2), y+(m/2));
        tile1(l / 2, m / 2, x - (m / 2), y - (m / 2));
        tile2(l / 2, m / 2, x + (m / 2), y - (m/ 2));
    }
}
void tile2(int l, int m, int x, int y) {
    if (l == 2 || m == 1){
        printf("2 %d %d\n", x, y); return;
    }else{
        tile1(l / 2, m / 2, x - (m / 2), y - (m / 2));
        tile2(l / 2, m / 2, x , y );
        tile3(l / 2, m / 2, x + (m / 2), y + (m / 2));
        tile2(l / 2, m / 2, x + (m / 2), y - (m / 2));
    }
}
void tile3(int l, int m, int x, int y) {
    if (l == 2 || m == 1){
        printf("3 %d %d\n", x, y); return;
    }else{
        tile2(l / 2, m / 2, x + (m / 2), y - (m / 2));
        tile3(l / 2, m / 2, x, y);
        tile3(l / 2, m / 2, x + (m / 2), y + (m / 2));
        tile4(l / 2, m / 2, x - (m / 2), y + (m / 2));
    }
}
void tile4(int l, int m, int x, int y) {
    if (l == 2 || m == 1){
        printf("4 %d %d\n", x, y); return;
    }
    else{
        tile3(l / 2, m / 2, x + (m / 2), y + (m / 2));
        tile4(l / 2, m / 2, x, y);
        tile4(l / 2, m / 2, x - (m / 2), y + (m / 2));
        tile1(l / 2, m / 2, x - (m / 2), y - (m / 2));
    }
}
int main(){
    int m, l,x=0,y=0;
    scanf("%d%d", &l, &m);
    int i = l;
    while (i > m){
        x += i / 2; 
        y += i / 2;
        tile1(i, i / 2, x, y);
        i /= 2;
    }
    return 0;
}
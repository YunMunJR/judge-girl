#include <stdio.h>
int route(int obstacles[12][12], int r, int c,int curr_x,int curr_y){
    if(curr_x<c-1 && curr_y>0){
        if(obstacles[curr_y][curr_x + 1] == 0 || obstacles[curr_y - 1][curr_x] == 0){
            if(obstacles[curr_y][curr_x + 1] == 0 && obstacles[curr_y - 1][curr_x] == 0){
                return 0;
            }else{
                if(obstacles[curr_y][curr_x + 1] == 0){
                    return route(obstacles, r, c, curr_x, curr_y - 1);
                }else if (obstacles[curr_y - 1][curr_x] == 0){
                    return route(obstacles, r, c, curr_x + 1, curr_y);
                }     
            }
        }else{
            return (route(obstacles, r, c, curr_x, curr_y - 1)+ route(obstacles, r, c, curr_x + 1, curr_y));
        }           
    }else if(curr_x==c-1){
        if(obstacles[curr_y-1][curr_x] != 0){
            if (curr_y == 1){
                return 1;
            }else{
                return route(obstacles, r, c, curr_x, curr_y - 1);
            }      
        }else{
            return 0;
        }   
    }else if(curr_y == 0){
        if (obstacles[curr_y][curr_x+1] != 0){
            if (curr_x == c - 2){
                return 1;
            }else{
                return route(obstacles, r, c, curr_x + 1, curr_y);
            }   
        }else{
            return 0;
        }    
    }
    return 0;
}
int main(){
    int obstacles[12][12] = { 0 },r,c;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &obstacles[i][j]);
        }  
    }
    int ways = route(obstacles, r, c, 0, r - 1);
    printf("%d", ways);
    return 0;
}
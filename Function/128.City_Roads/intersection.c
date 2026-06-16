#include <stdio.h>
#include "intersection.h" 
void intersection(int map[100][100], int result[4]){
    int i,j,max,min,r1,r2,r3,r4,num;
    max=99;
    min=0;
    num=0;
    r1=0;
    r2=0;
    r3=0;
    r4=0;
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            num=0;
            if(map[i][j]==1){
                if((i!=min&&i!=max)&&(j!=min&&j!=max)){
                    if (map[i+1][j]==1){
                        num++;
                    }
                    if(map[i-1][j]==1){
                        num++;
                    }
                    if(map[i][j+1]==1){
                        num++;
                    }
                    if(map[i][j-1]==1){
                        num++;
                    }
                    if(num!=2){
                        switch (num){
                            case 1:
                                r4++;
                                break;
                            case 3:
                                r2++;
                                break;
                            case 4:
                                r1++;
                                break;
                            default:
                                break; 
                        }
                    }else{
                        if(!((map[i+1][j]==1&&map[i-1][j]==1)||(map[i][j+1]==1&&map[i][j-1]==1))){
                            r3++; 
                        }
                    } 
                }else if(j==min&&(i!=min&&i!=max)){
                    if (map[i+1][j]==1){
                        num++;
                    }
                    if(map[i-1][j]==1){
                        num++;
                    }
                    if(map[i][j+1]==1){
                        num++;
                    }
                    if(num!=2){
                        switch (num){
                            case 1:
                                r4++;
                                break;
                            case 3:
                                r2++;
                                break;
                            default:
                                break; 
                        }
                    }else{
                        if(!(map[i+1][j]==1&&map[i-1][j]==1)){
                            r3++; 
                        }
                    }
                }else if(j==max&&(i!=min&&i!=max)){
                    if (map[i+1][j]==1){
                        num++;
                    }
                    if(map[i-1][j]==1){
                        num++;
                    }
                    if(map[i][j-1]==1){
                        num++;
                    }
                    if(num!=2){
                        switch (num){
                            case 1:
                                r4++;
                                break;
                            case 3:
                                r2++;
                                break;
                            default:
                                break; 
                        }
                    }else{
                        if(!(map[i+1][j]==1&&map[i-1][j]==1)){
                            r3++;
                        }  
                    }
                }else if(i==max&&(j!=min&&j!=max)){
                    if (map[i][j+1]==1){
                        num++;
                    }
                    if(map[i-1][j]==1){
                        num++;
                    }
                    if(map[i][j-1]==1){
                        num++;
                    }
                    if(num!=2){
                        switch (num){
                            case 1:
                                r4++;
                                break;
                            case 3:
                                r2++;
                                break;
                            default:
                                break; 
                        }
                    }else{
                        if(!(map[i][j+1]==1&&map[i][j-1]==1)){
                            r3++; 
                        }      
                    }
                }else if (i==min&&(j!=min&&j!=max)){
                    if (map[i][j+1]==1){
                        num++;
                    }
                    if(map[i+1][j]==1){
                        num++;
                    }
                    if(map[i][j-1]==1){
                        num++;
                    }
                    if(num!=2){
                        switch (num){
                            case 1:
                                r4++;
                                break;
                            case 3:
                                r2++;
                                break;
                            default:
                                break; 
                        }
                    }else{
                        if(!(map[i][j+1]==1&&map[i][j-1]==1)){
                            r3++; 
                        }      
                    }
                }else if(i==min&&j==min){
                    if(map[i+1][j]==1){
                        num++;
                    }
                    if(map[i][j+1]==1){
                        num++;
                    }
                    switch (num){
                        case 1:
                            r4++;
                            break;
                        case 2:
                            r3++;
                            break;
                        default:
                            break; 
                    }
                }else if(i==max&&j==min){
                    if(map[i-1][j]==1){
                        num++;
                    }
                    if(map[i][j+1]==1){
                        num++;
                    }
                    switch (num){
                        case 1:
                            r4++;
                            break;
                        case 2:
                            r3++;
                            break;
                        default:
                            break; 
                    }
                }else if(i==min&&j==max){
                    if(map[i+1][j]==1){
                        num++;
                    }
                    if(map[i][j-1]==1){
                        num++;
                    }  
                    switch (num){
                        case 1:
                            r4++;
                            break;
                        case 2:
                            r3++;
                            break;
                        default:
                            break; 
                    }
                }else if(i==max&&j==max){
                    if(map[i-1][j]==1){
                        num++;
                    }
                    if(map[i][j-1]==1){
                        num++;
                    }
                    switch (num){
                        case 1:
                            r4++;
                            break;
                        case 2:
                            r3++;
                            break;
                        default:
                            break; 
                    }
                }
            }     
        }
    }
    result[0]=r1;
    result[1]=r2;
    result[2]=r3;
    result[3]=r4;   
}
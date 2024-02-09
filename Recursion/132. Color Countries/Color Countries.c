#define MAXCOLOR 8
#define MAXCOUNTRIES 20
#include <stdio.h>
int repeat_or_not(int countrymap[][4],int colormap[][4], int i, int j) {
    int re = 0;
    if(((colormap[i][j + 1] == colormap[i][j]) && (countrymap[i][j + 1] != countrymap[i][j])) || ((colormap[i][j - 1] == colormap[i][j]) && (countrymap[i][j - 1] != countrymap[i][j]))){
        re = 1;
    }
    return re;
}
void init(int colormap[][4], int countrymap[][4],int countryindex,int P) {
    for (int i = 1; i < P + 1; i++) {
        for (int j = 1; j < 3; j++) {
            if(countrymap[i][j] == countryindex){
                colormap[i][j] = 0;
            }
        }
    }
}
int fill_countrymap(int countrymap[][4], int colormap[][4], int N, int C, int P, int countrycolor[], int countryindex, int colorindex) {
    int repeat = 0; 
    if(countryindex != N ) {
        if(countryindex >= 0){
            if(colorindex <= C) {
                countrycolor[countryindex] = colorindex;
                for (int i = 1; i < P + 1; i++) {
                    for (int j = 1; j < 3; j++) {
                        if(countrymap[i][j] == countryindex) {
                            colormap[i][j] = colorindex; 
                            if(repeat_or_not(countrymap, colormap, i, j) == 1){
                                repeat = 1;
                            }
                        }
                    }
                }
            }else {
                countrycolor[countryindex] = 0;
                return fill_countrymap(countrymap, colormap, N, C, P, countrycolor, countryindex - 1, countrycolor[countryindex - 1] + 1);
            }
            if (repeat) {
                init(colormap, countrymap, countryindex, P);
                if (colorindex < C){
                    return fill_countrymap(countrymap, colormap, N, C, P, countrycolor, countryindex, colorindex + 1);
                }else {
                    countrycolor[countryindex] = 0;
                    init(colormap, countrymap, countryindex, P);
                    return fill_countrymap(countrymap, colormap, N, C, P, countrycolor, countryindex - 1, countrycolor[countryindex - 1] + 1);
                }
            }else {
                return fill_countrymap(countrymap, colormap, N, C, P, countrycolor, countryindex + 1, 1);
            }
        }else{
            return 0;
        }
    }else{
        return 1;
    }
}
int main() {
    int N, C, P, countries_map[100][4] = { 0 }, color_map[100][4] = { 0 } , countries_color[MAXCOUNTRIES] = { 0 }; 
    int findanswer = 0;
    scanf("%d%d%d", &N, &C, &P);
    for (int i = 1; i < P + 1; i++) {
        scanf("%d%d", &countries_map[i][1], &countries_map[i][2]);    
    }
    if (fill_countrymap(countries_map, color_map, N, C, P, countries_color, 0, 1)) {
        for (int i = 0; i < N; i++) {
            printf("%d\n", countries_color[i]);
        }
    }else{
        fputs("no solution.\n",stdout);
    }
    return 0;
}
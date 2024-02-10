#include <stdio.h>
#include <stdlib.h>
int gcd(long long n1, long long m1){
    long long b=1;
    while (b != 0){
        b = n1 % m1;
        n1 = m1;
        m1 = b;
    }
    return n1;
}
typedef struct fraction {
    long long up;
    long long down;
}frac;
int main(){
    int N;
    scanf("%d",&N);
    frac temp[2] = {0,0};
    long long a[500][2], fractions[450][2] = { 0,0 };
    int gcda2=1, gcda1=1, gcdtemp1=1, gcdtemp2=1,gcdfrac=1;
    a[0][0] = 1; a[0][1] = 1;
    for (int i = 0; i < (N * (N + 1)) / 2; i++){
        scanf("%lld%lld",&fractions[i][0], &fractions[i][1]);
    }
    for (int i = 0; i < (N * (N + 1)) / 2; i++){
        if (fractions[i][0] == 0 || fractions[i][1] == 0){
            if (fractions[i][0] == 0){
                fractions[i][1] = 1;
            }else{
                fractions[i][0] = 1;
            }     
        }else{
            gcdfrac = gcd(fractions[i][0], fractions[i][1]);
            fractions[i][0] /= gcdfrac;
            fractions[i][1] /= gcdfrac;
        }
    }
    for (int i = 1; i <= N; i++){
        a[(i * (i + 1)) / 2][0] = a[(i * (i - 1)) / 2][0] * fractions[(i * (i - 1)) / 2][0];
        a[(i * (i + 1)) / 2][1] = a[(i * (i - 1)) / 2][1] * (fractions[(i * (i - 1)) / 2][1] + fractions[(i * (i - 1)) / 2][0]);
        a[((i+2) * (i + 1)-2) / 2][0] = a[(i * (i + 1) -2) / 2][0] * fractions[(i * (i + 1) -2) / 2][1];
        a[((i + 2) * (i + 1) - 2) / 2][1] = a[(i * (i + 1) - 2) / 2][1] * (fractions[(i * (i + 1) - 2) / 2][1] + fractions[(i * (i + 1) - 2) / 2][0]);
        gcda1 = gcd(a[(i * (i + 1)) / 2][0], a[(i * (i + 1)) / 2][1]); 
        gcda2 = gcd(a[((i + 2) * (i + 1) - 2) / 2][0], a[((i + 2) * (i + 1) - 2) / 2][1]);
        a[(i * (i + 1)) / 2][0] /= gcda1;
        a[(i * (i + 1)) / 2][1] /= gcda1;
        a[((i + 2) * (i + 1) - 2) / 2][0] /= gcda2;
        a[((i + 2) * (i + 1) - 2) / 2][1] /= gcda2;
            for (int j = 1; j < i; j++){
                temp[0].up = a[((i * (i - 1)) / 2) + j - 1][0] * fractions[((i * (i - 1)) / 2) + j - 1][1];
                temp[0].down = a[((i * (i - 1)) / 2) + j - 1][1] * (fractions[((i * (i - 1)) / 2) + j - 1][1] + fractions[((i * (i - 1)) / 2) + j - 1][0]);
                temp[1].up = a[((i * (i - 1)) / 2) + j][0] * fractions[((i * (i - 1)) / 2) + j][0];
                temp[1].down = a[((i * (i - 1)) / 2) + j][1] * (fractions[((i * (i - 1)) / 2) + j][1] + fractions[((i * (i - 1)) / 2) + j][0]);
                gcdtemp1 = gcd(temp[0].up, temp[0].down); 
                gcdtemp2 = gcd(temp[1].up, temp[1].down);
                temp[0].up /= gcdtemp1;
                temp[0].down /= gcdtemp1;
                temp[1].up /= gcdtemp2;
                temp[1].down /= gcdtemp2;
                a[(i * (i + 1) / 2) + j][0] = temp[0].up * temp[1].down + temp[0].down * temp[1].up;
                a[(i * (i + 1) / 2) + j][1] = temp[0].down * temp[1].down;
                gcda1 = gcd(a[(i * (i + 1) / 2) + j][0], a[(i * (i + 1) / 2) + j][1]); 
                a[(i * (i + 1) / 2) + j][0] /= gcda1;
                a[(i * (i + 1) / 2) + j][1] /= gcda1;
                temp[0].up = 0;
                temp[0].down = 0; 
                temp[1].up = 0; 
                temp[1].down = 0; 
                gcda1 = 0; 
                gcda2 = 0;
        }
    }
    for (int i = (N * (N + 1)) / 2; i < ((N + 1) * (N + 2)) / 2; i++){
        printf("%lld/%lld", a[i][0], a[i][1]);
        (i!= ((N + 1) * (N + 2)-2) / 2)&&putchar('\n');
    }
    return 0;
}
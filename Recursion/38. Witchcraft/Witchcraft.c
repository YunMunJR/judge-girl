#include <stdio.h>
int GCD(int a, int b){
    if (a != 0 && b != 0){
        int m = 1;
        while (m != 0){
            m = a % b; a = b; b = m;
        }
        return a;
    }
    else{
        return 1;
    }     
}
int witchcraft(int D, int a, int b, int c, int A, int B, int C, char ch, int arr[]){
    if (D > 0){
        if (ch == 'a'){
            if (D < A || a < 1){
                return witchcraft(D, a, b, c, A, B, C, 'b', arr);
            }else{
                return witchcraft(D, a, b, c, A, B, C, 'b', arr) || witchcraft(D - A, a - 1, b, c, A, B, C, ch, arr);
            }       
        }else if (ch == 'b'){
            if (D < B || b < 1){
                return witchcraft(D, a, b, c, A, B, C, 'c', arr);
            }else{
                return witchcraft(D, a, b, c, A, B, C, 'c', arr) || witchcraft(D - B, a, b - 1, c, A, B, C, ch, arr);
            }         
        }else{
            if (D < C || c < 1){
                return 0;
            }else{
                return 0 || witchcraft(D - C, a, b, c - 1, A, B, C, ch, arr);
            }          
        }
    }else if (D == 0){
        return 1;
    }else{
        return 0;
    }      
}
int main(){
    int n, A, B, C, D, a, b, c, num[3], Case = 0;
    int TorF[1000] = { 0 };
    scanf("%d", &n);
    while (Case < n){
        scanf("%d%d%d%d%d%d%d", &D, &a, &b, &c, &A, &B, &C);
        num[0] = a; num[1] = b; num[2] = c;
        char ch = 'a';
        int gcd2 = GCD(D, GCD(a, GCD(b, c)));
        D /= gcd2; 
        a /= gcd2; 
        b /= gcd2; 
        c /= gcd2;
        if (A == B){
            if (B == C){
                a += (b + c); 
                b = 0; 
                c = 0;
                int gcd1 = GCD(D, a); 
                D /= gcd1; 
                a /= gcd1;
            }else{
                a += b; 
                b = 0;
                int gcd2 = GCD(D, GCD(a, c)); 
                D /= gcd2; 
                a /= gcd2; 
                c /= gcd2;
            }
        }else{
            if (A == C){
                a += c; 
                c = 0;
                int gcd3 = GCD(D, GCD(a, b)); 
                D /= gcd3; 
                a /= gcd3; 
                b /= gcd3;
            }if (B == C){
                b += c; 
                c = 0;
                int gcd4 = GCD(D, GCD(a, b)); 
                D /= gcd4; 
                a /= gcd4; 
                b /= gcd4;
            }
        }
        TorF[Case] = witchcraft(D, a, b, c, A, B, C, ch, num);
        Case++;
    }
    for (int i = 0; i < n; i++){
        printf("%s", (TorF[i]) == 1 ? "yes" : "no");
        (i!=n-1)&&putchar('\n');         
    }
    return 0;
}
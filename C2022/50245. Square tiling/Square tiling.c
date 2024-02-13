#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int left;
    int top;
    int right;
    int bottom;
    int can;
}Square;
int solve(Square s[],int a[5][5],int idx,int n){
    int c=idx/n,r=idx%n;
    if(idx==n*n){
        return 1;
    }
    int find=0;
    int cc1=c-1,rr1=r,i=1;
    int cc2=c,rr2=r-1;
    for(int i=0;i<n*n;i++){
        if(s[i].can){
            a[c][r]=i;
            s[i].can=0;
            if(c==0||r==0){
                if(c==0&&r==0){
                    if(!(find||solve(s,a,idx+1,n))){
                        a[0][0]=-1;
                        s[i].can=1;
                        find=find||0;
                    }else{
                        return 1;
                    } 
                }else{
                    if(c==0){
                        if(s[i].left!=s[a[cc2][rr2]].right){
                            a[0][r]=-1;
                            s[i].can=1;
                            find=find||0;
                        }else{
                            if(!(find||solve(s,a,idx+1,n))){
                                a[0][r]=-1;
                                s[i].can=1;
                                find=find||0;
                            }else{
                                return 1;
                            }
                        }
                    }else{
                        if(s[i].top!=s[a[cc1][rr1]].bottom){
                            a[c][0]=-1;
                            s[i].can=1;
                            find=find||0;
                        }else{
                            if(!(find||solve(s,a,idx+1,n))){
                                a[c][0]=-1;
                                s[i].can=1;
                                find=find||0;
                            }else{
                                return 1;
                            }
                        }
                    }
                }
            }else{
                if(s[i].top!=s[a[cc1][rr1]].bottom||s[i].left!=s[a[cc2][rr2]].right){
                    a[c][r]=-1;
                    s[i].can=1;
                    find=find||0;
                }else{
                    if(!(find||solve(s,a,idx+1,n))){
                        a[c][r]=-1;
                        s[i].can=-1;
                        find=find||0;
                    }else{
                        return 1;
                    }
                }
            }
        }
        if(find){
            return 1;
        }
    }
    return 0;
}
int main(){
    Square s[25];
    int a[5][5];
    int n;
    while(scanf("%d",&n)!=EOF){
        int num=n*n;
        for(int i=0;i<num;i++){
            scanf("%d%d%d%d",&s[i].left,&s[i].top,&s[i].right,&s[i].bottom);
            a[i/n][i%n]=-1;
            s[i].can=1;
        }
        int ss=solve(s,a,0,n);
        if(ss){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    printf("%d",a[i][j]);
                    (j!=n-1)&&putchar(' ');
                }
                putchar('\n');
            }
        }else{
            fputs("no solution\n",stdout);
        }
    }
    
    return 0;
}
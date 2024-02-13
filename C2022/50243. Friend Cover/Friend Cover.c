#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int n[64];
    int b;
    int num;   
}re;
int cmp(const void*a,const void*b){
    if(*(int*)a>*(int*)b){
        return 1;
    }else{
        return -1;
    }
}
void print(re r){
    for(int i=0;i<64;i++){
        (r.n[i])&&printf("%d\n",i);
    }
}
re find(re r1,re r2){
    for(int i=0;i<64;i++){
        if(!(r1.n[i]&&r2.n[i])){
            if(r1.n[i]){
                return r1;
            }
            if(r2.n[i]){
                return r2;
            }
        }
    }
}
re solve(int friend[2048][2],int people[64],int m,int idx){ 
    if(people[idx]){
        int no=0;
        for(int i=0;i<m;i++){
            if(!people[friend[i][0]]&&!people[friend[i][1]]){
                no=1;
                break;
            }
        }
        if(no){
            re r;
            r.b=0;
            return r;
        }else{
            if(idx<0){
                int c;
                re r;
                r.b=1;
                r.num=0;
                for(int i=0;i<64;i++){
                    r.n[i]=0;
                    (people[i]!=0)&&((r.n[i]=1)&&(r.num++));     
                }
                return r;
            }
            people[idx]=0;
            re r1=solve(friend,people,m,idx-1);
            people[idx]=1;
            re r2=solve(friend,people,m,idx-1);
            if(r1.b&&r2.b){
                if(r1.num<r2.num){
                    return r1;
                }else if(r1.num>r2.num){
                    return r2;
                }else{
                    return find(r1,r2);
                }
            }else{
                if(r1.b){
                    return r1;
                }else{
                    return r2;
                }
            }
        }
    }else{
        return solve(friend,people,m,idx-1);
    }
}
int main(){
    int friend[2048][2],people[64];
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<64;i++){
        people[i]=0;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&friend[i][0],&friend[i][1]);
        qsort(friend[i],2,sizeof(int),cmp);
        people[friend[i][0]]=1;
        people[friend[i][1]]=1;
    }
    if(people[n-1]){
        people[n-1]=0;
        re r1=solve(friend,people,m,n-2);
        people[n-1]=1;
        re r2=solve(friend,people,m,n-2);
        if(r1.b&&r2.b){
            if(r1.num<r2.num){
                print(r1);
            }else if(r1.num>r2.num){
                print(r2);
            }else{
                print(find(r1,r2));
            }    
        }else{
            if(r1.b||r2.b){
                if(r1.b){
                    print(r1);
                }else{
                    print(r2);
                }
            }
        }
    }else{
        re r=solve(friend,people,m,n-2);
        if(r.b){
            print(r);
        }
    } 
    return 0;
}
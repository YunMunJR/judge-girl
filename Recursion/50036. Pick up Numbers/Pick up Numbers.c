#include <stdio.h>
int pick_numbers(int num[], int k, int N,int M,int pick_times,int how_many_numbers,int sum){
    if (!(pick_times < k)){
        if (how_many_numbers > N||sum>M){
            return 0;
        }else{
            if (how_many_numbers==N){
                return 1;
            }else{
                return (pick_numbers(num, k, N, M, pick_times + 1, how_many_numbers + 1, sum + num[how_many_numbers])
                + pick_numbers(num, k, N, M, pick_times, how_many_numbers + 1, sum));
            }           
        }
    }else{
        if (!(how_many_numbers < N)){
            return 0;
        }else{
            return (pick_numbers(num, k, N, M, pick_times + 1, how_many_numbers + 1, sum + num[how_many_numbers])
            + pick_numbers(num, k, N, M, pick_times, how_many_numbers + 1, sum));
        }     
    }
}
int main(){
    int k, N, M,num[20]={0};
    scanf("%d%d%d", &k, &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    int conditions = pick_numbers(num, k, N, M, 0, 0, 0);
    printf("%d", conditions);
    return 0;
}
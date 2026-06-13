# 題目描述
Morris 正在解某一道題，輸入的每一組測資只會需要一個串列 (List)，該筆測資運行結束後便會刪除串列。現在需要<br>請你協助 Morris 建立這一個串列。
## utils.h
這部份不需要變動。
![util.h](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10118.Make_a_List/utils.h)
## util.c
![util.c](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10118.Make_a_List/utils.c)
## main.c
這部份不需要變動。
![main.c](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10118.Make_a_List/main.c)
## list.c
![list.c](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10118.Make_a_List/template-list.c)
# 輸入格式
輸入第一行會有一個亂數種子 $S$，接著會有數行，每一行上會有一個整數 $N$，請產生一個長度為 $N$ 個串列。你可以假設 $N \leq 2000000$，同時串列不會進行刪除操作。
# 輸出格式
輸出串列結果。
# 範例輸入
```
514
1
2
3
```
# 範例輸出
```
58598 ->
127215 -> 79852 ->
222509 -> 178626 -> 29563 ->
```
# 編譯參數
```
gcc -std=c99 -O2 -c list.c
gcc -std=c99 -O2 -c utils.c
gcc -std=c99 -O2 list.o utils.o main.c -lm
```
# Testdata Set
![Testdata_Set](https://github.com/YunMunJR/judge-girl/tree/main/Advanced/10118.Make_a_List/p10118_testdata)

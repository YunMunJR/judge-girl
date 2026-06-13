# 題目描述
給予數個成績表單，每一個成績表單的欄位個數是變動的。第一個欄位為長度小於等於 31 個字符串表示名字，其他欄位<br>會是一個整數型態 (signed 32-bits) 的成績格式。一個表單最多 128 個成績欄位，最多有 256 個成績記錄。
## 範例說明
A 表單為 <br>
| name/score | ex1 | ex2 | ex3 |
|:-----------|:---:|:---:|:---:|
|  pangfeng  | 100 | 100 | 99  |
|  morris    | 0   | 0   | 100 |

打印出 A 表單時會給定排序方法
- 例如按照 (ex1, ex2, ex3) 則表示先按照 ex1 進行降排序，相同時再按照 ex2，再相同最後是 ex3。最後輸出結果即為 <br>
> ```
> pangfeng, 100, 100, 99
> morris, 0, 0, 100
> ```
- 例如按照 (ex3, ex1, ex2) 則表示先按照 ex3 進行降排序，相同時再按照 ex1，再相同最後是 ex2。最後輸出結果即為 <br>
> ```
> morris, 0, 0, 100
> pangfeng, 100, 100, 99
> ```
## 實作細節
接下來，你需要實作以下三個 function<br>
- `void init(ExamTable *self, int n);`<br>
初始化某個表單且成績欄位恰好 n 個。
- `void addrow(ExamTable *self, char *name, int score[]);`<br>
增加某個表單的資料。
- `void print(ExamTable *self, int order[]);`<br>
根據 order 給定的順序進行排序後輸出。若成績都一樣，最後按照名字字典順序由小排到大。請參考範例輸出。
## main.c
![main.c](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10056.Sort_Table/main.c)
# 輸入格式
第一行有一個整數 $n$ 表示有 $n$ 個表單，第二行上有 n 個整數，分別表示 $table0, table1, ..., tablen−1$ 的成績欄位數 #$field$<sub>$i$</sub>，第三行會有一個整數 $q$，表示接下來的操作次數。<br>
接下來的 $q$ 行，每一行一組操作。
# 範例輸入
```
2
3 4
10
1 0 pangfeng 100 100 99
1 0 morris 0 0 100
2 0 0 1 2
2 0 2 0 1
1 1 hank 5 5 6 6
1 1 scott 5 7 6 6
1 1 ahmad 5 5 6 7
2 1 0 1 2 3
2 1 3 1 2 0
2 0 2 0 1
```
# 範例輸出
```
----- table begin -----
pangfeng, 100, 100, 99
morris, 0, 0, 100
----- end         -----
----- table begin -----
morris, 0, 0, 100
pangfeng, 100, 100, 99
----- end         -----
----- table begin -----
scott, 5, 7, 6, 6
ahmad, 5, 5, 6, 7
hank, 5, 5, 6, 6
----- end         -----
----- table begin -----
ahmad, 5, 5, 6, 7
scott, 5, 7, 6, 6
hank, 5, 5, 6, 6
----- end         -----
----- table begin -----
morris, 0, 0, 100
pangfeng, 100, 100, 99
----- end         -----
```
# Hint
全部透過實作 function 的輸出和回傳值進行測試，不管你實作的 struct 細節。
# Testdata Set
![Testdata_Set](https://github.com/YunMunJR/judge-girl/tree/main/Advanced/10056.Sort_Table/p10056_testdata)
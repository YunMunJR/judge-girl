# 背景
在早期密碼世界中， 各種運算都先講求速度，不管是在硬體、軟體利用各種數學定義來設計加密算法就為了加快幾<br>倍的速度，但在近代加密中，加速方法會造成硬體實作攻擊，速度和安全，你選擇哪一個呢。
# 題目描述
<div align="center">
ab ≡ x mod n
</div>
已知 $a,b,n$，求出 $x$。

# 輸入格式
有多組測資，每一組測資一行三個整數 $a,b,n$，其中 $0$ &leq; $a,b$ &leq; $1018,1$ &leq;  $n$ &leq; $1018$。
# 輸出格式
對於每一組測資輸出一行，ab  mod n 的結果。
# 範例輸入
```
3 5 7
2 4 3
2 0 2
5 1 4
```
# 範例輸出
```
1
2
0
1
```
# 提示
![Wiki Modular arithmetic](https://en.wikipedia.org/wiki/Modular_arithmetic) 答案在裡頭
# Testdata Set
![Testdata_Set](https://github.com/YunMunJR/judge-girl/tree/main/Advanced/10031.Fast_64-bits_Modular_Arithmetic/p10031_testdata)
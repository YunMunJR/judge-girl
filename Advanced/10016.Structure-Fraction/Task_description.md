# 背景
某 M 需要小夥伴，批改娘改一改就系統就 crash 掉，題目描述都不見了 ... 某 M 不小心把 multiply 拼成 multipy :3 累了
# 題目描述
分別實作分數約分、加減乘除五個函數。<br>
系統會自動加入 `main.c`，只需要上傳 `fraction.h` 和 `fraction.c` 即可。<br>
本地編譯參數為 
```
gcc main.c fraction.c -std=c99 -O2
```
若使用 Dev-C++ 的同學，可以利用 Tools > Compile Options > General > 勾選 Add the following commands when calling the linker: -<br>static-libgcc -std=c99 fraction.c
## main.c
![main.c](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10016.Structure-Fraction/main.c)
## fraction.h
![fraction.h](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10016.Structure-Fraction/fraction.h)
## fraction.c
![fraction.c](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10016.Structure-Fraction/template-fraction.c)
# Sample Input
```
1
0 1 50 30
```
# Sample Output
```
5 / 3
```
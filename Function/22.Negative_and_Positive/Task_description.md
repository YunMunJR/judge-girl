# Task Description
Write a function `posneg` to find the number of positive and negative integers in a 5 by 5 integer array. The prototype of `posneg` is as follows.
```
void posneg(int array[5][5], int result[2]);
```
The number of negative integers should be place in `result[0]`, and the number of positive integers should be place in<br> `result[1]`. You only need to write the function and we will use a main program to test the correctness of your function.
The main program is as follows.<br>
![main.c](https://github.com/YunMunJR/judge-girl/blob/main/Function/22.Negative_and_Positive/main.c)
# Input Format
There are five lines in the input. Each line has five integers.
# Output Format
There are two lines in the output. The first line has the number of negative integers, and the second line has the number of positive<br> integers in the matrix.
# Sample Input
```
0 2 3 4 5
7 -7 7 7 7
8 9 -10 11 2
45 8 9 45 3
0 0 0 0 0
```
# Sample Output
```
2
17
```
# Testdata Set
![Testdata_Set](https://github.com/YunMunJR/judge-girl/tree/main/Function/22.Negative_and_Positive/p22_testdata)
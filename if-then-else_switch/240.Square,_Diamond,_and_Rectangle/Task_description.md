# Task Description
Given four different points on the plane, determine the shape of this polygon. There are several cases.<br>
- If the length of the four sides are the same, and the four angles are right, then it is a square. For example, the polygon by<br>$(−1,0),(0,1),(1,0),(0,−1)$ is a square.
- If the length of the four sides are the same, but the four angles are not right angle, then it is a diamond. For example, polygon<br>by $(−2,0),(0,1),(2,0),(0,−1)$ is a diamond.
- If the length of the four sides are not the same, but the four angles are right angle, then it is a rectangle. For example, polygon<br>by $(0,0),(0,1),(2,1),(2,0)$ is a rectangle.<br>
給定平面上四個點，它們彼此不共點，請判斷這個多邊形的形狀，有以下三種可能：<br>
- 如果四邊長度相同以及角度為直角，它們即是正方形，如多邊形 $(−1,0),(0,1),(1,0),(0,−1)$ 就是個正方形。
- 如果四邊長度相同但角度不是直角，它們即是菱形，如多邊形 $(−2,0),(0,1),(2,0),(0,−1)$ 就是個菱形。
- 如果四邊長度不同且四個角均是直角，它們即是長方形，如 $(0,0),(0,1),(2,1),(2,0)$ 就是個長方形。
- 不屬於上述三者，請回報 `other` <br>
# Input
The first line has the number of test data $n$. $n$ is at least 1 and at most 100000. Each of he next $n$ line has a test data. Each test data<br>line has 8 integers for the four points.<br>
The first two are the $x$ and $y$ coordinates of the first point, etc.<br>
Since the difference between two $x$ coordinates, or two $y$ coordinates is bounded by 10000, you may assume that the computation<br>can be safely done with int.<br>
It is also guaranteed that there will be no three points in a straight line, and the quadrilateral is convex and unique. The four points<br>may be given in `any order`.
# Output
Output the shape for each input line. You should output `square`, `diamond`, `rectangle` according to the definition above.<br>If the polygon does not fit into any definition, output `other`.
# Sample input
```
4
-1 0 0 -1 0 1 1 0
-2 0 2 0 0 -1 0 1
0 1 2 1 0 0 2 0
0 1 0 0 2 1 2 -10
```
# Sample output
```
square
diamond
rectangle
other
```
# Hint
You can easily check whether an angle is a right angle by Pythagorean theorem - $a^{2}$+$b^{2}$=$c^{2}$. <br>
你可以使用向量外積的正負號，讓輸入的點按照順或逆時針的方式排列。
# Testdata Set
![Testdat_Set](https://github.com/YunMunJR/judge-girl/tree/main/if-then-else_switch/240.Square%2C_Diamond%2C_and_Rectangle/p240_testdata)

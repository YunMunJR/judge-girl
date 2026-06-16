# Task Description
Write a program to solve a system of equations. In particular we are given an $n$ by $n$ upper triangular matrix $A$ and a $n$ by 1 vector $y$<br>, and we would like to find another $n$ by 1 vector $x$ so that $Ax=y$. Since $A$ is upper triangular, i.e., all the elements below the<br> diagonal are zero, we can use a simple procedure called backward substitution to get the vector $x$. Since A<sub>n,n</sub> × x<sub>n</sub> = y<sub>n</sub>, so we<br> conclude that x<sub>n</sub> = y<sub>n</sub> / A<sub>n,n</sub>. Since we know x<sub>n</sub> now, we can easily compute x<sub>n−1</sub>, then x<sub>n−2</sub>, and so on, until we finally compute x<sub>1</sub>.
# Input
he first line of the input has the number of rows and columns $n$. $n$ is between 1 and 16. Each of the following $n$ lines has $n$ double<br> numbers in $A$. Each of the following $n$ lines has the numbers in $y$. Note that all elements of matrix and vector are double numbers.
# Output
The output has $n$ lines. Each line is a number in $x$. You should output the double numbers in `%f\n` format.
# Sample input
```
3
1.0 2.0 3.0
0.0 2.0 1.0
0.0 0.0 4.0
2.0
3.0
-4.0
```
# Sample output
```
1.000000
2.000000
-1.000000
```
# Testdata Set
![Testdata_Set](https://github.com/YunMunJR/judge-girl/tree/main/Floating_Point_Numbers/103.Triangular_Matrix_Solver/p103_testdata)
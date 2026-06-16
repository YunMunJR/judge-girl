# Task Description
Write a program to play bingo. A bingo board has $m$ rows and $m$ columns. Each entry has a different number from 1 to $m×m$. The<br>numbers from 1 to $m×m$ will be randomly called. If a player has all the numbers in a row, a column, or a diagonal called he can<br>declare bingo and win the game. Now given the bingo boards of $n$ players, determine who wins the bingo.
# Input
The first line of the input has $n$ and $m$. Each of the next $m$ lines has the $m$ numbers of the bingo board of the first player. The next<br>line has the name of the second player, and the next $m$ lines have the numbers for the second player, and so on. The next line has<br>$m×m$ numbers that are called in sequence during the bingo game
# Output
Print the indices of the winners of the game and by which number they won the game. If there are more than one winner, print the<br>player indices one by one according to the order they appear in input.
# Limits
- $n$ positive is no more than 10.
- $m$ is positive and no more than 256.
- The length of a name is positive and no more than 64. The name consist of only letters.
# Sample input
```
2 3
Alice
1 2 3
4 5 6
7 8 9
Blob
1 2 3
4 5 6
7 8 9
1 2 4 8 6 3 9 5 7
```
# Sample output
```
3 Alice Blob
```
# Testdata Set
![Testdata_Set](https://github.com/YunMunJR/judge-girl/tree/main/Array/99.Bingo/p99_testdata)

# Task Description
Write a program to simulate two bouncing balls in a box. Let's assume that there is a box of width $X$ and height $Y$, and two balls moving within the box. The initial positions of these two balls<br> are different and given as (x<sub>1</sub>,y<sub>1</sub>) and (x<sub>2</sub>,y<sub>2</sub>) respectively, and<br> 1 < x<sub>1</sub>,x<sub>2</sub> < $X$, 1 < y<sub>1</sub>,y<sub>2</sub> < $Y$. The moving direction of these balls are given as (dx<sub>1</sub>,dy<sub>1</sub>) and (dx<sub>2</sub>,dy<sub>2</sub>). The balls move 1 unit<br> at a second and they always move in 45 degree angle, therefore all dx and dy are either 1 or −1. For example, suppose (x<sub>1</sub>,y<sub>1</sub>)<br> is $(3,4)$ and (dx<sub>1</sub>,dy<sub>1</sub>) is $(−1,1)$ then after one second the first ball will move to $(2,5)$.<br>
The ball will bounce when it hits the wall of the box. Since the ball always moves in 45 degree angle, it is easy to compute its path.<br> For example, suppose (x<sub>1</sub>,y<sub>1</sub>) is $(2,4)$ and (dx<sub>1</sub>,dy<sub>1</sub>) is $(−1,1)$ then the position of the first ball is $(2,4)$, $(1,5)$, $(2,6)$,... etc. If<br> the ball hits a corner, it bounces back the way it came in.<br>
The balls may hit each other and bounce back. We determine if two balls hit into each other by checking whether their positions are<br> the same after they move into their new locations. For example, suppose (x<sub>1</sub>,y<sub>1</sub>) is $(3,4)$ and (dx<sub>1</sub>,dy<sub>1</sub>) is $(−1,1)$, and (x<sub>2</sub>,y<sub>2</sub>) is<br> $(3,6)$ and (dx<sub>1</sub>,dy<sub>1</sub>) is $(−1,−1)$, The first ball will go to $(3,4)$, $(2,5)$, $(1,4)$, ... and the second ball will go to $(3,6)$, $(2,5)$, $(1,6)$,<br> ..., etc.<br>
Note that by our rules two balls exchanging positions do not collide. I know this is against physics but I do not want to make this<br> problem complicated, so bear with me.
# Limits
- $5<X,Y<300$
# Input
The input are $X$,$Y$,x<sub>1</sub>,y<sub>1</sub>,x<sub>2</sub>,y<sub>2</sub>,dx<sub>1</sub>,dy<sub>1</sub>,dx<sub>2</sub>,dy<sub>2</sub>, and the number of seconds you need to simulate.
# Output
The output is the final position of these two balls, in x<sub>1</sub>,y<sub>1</sub>,x<sub>2</sub>,y<sub>2</sub> order.
# Sample input
```
20
20
3
4
3
6
-1
1
-1
-1
2
```
# Sample output
```
1
4
1
6
```
# Testdata Set
![Testdata_Set](https://github.com/YunMunJR/judge-girl/tree/main/Loop/203.Bouncing_Balls/p203_testdata)

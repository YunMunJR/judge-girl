# Task Description
Write a program to predict the fate of two robots. Suppose we have two robots running in an $M$ (horizontal) by $N$ (vertical) unit<br> grid. Both will move at the speed of one square per time step. The first robot carries $F1$ amount of fuel and the second robot carries<br> $F2$. If a robot runs out of fuel, it will stop at that square. Moving to a new square requires one unit of fuel. During the first $N1$ time<br> steps, the first robot $R1$ will move to the north; then, it will move towards the east during the next $E1$ time steps. The first robot<br> will repeat this pattern until it runs out of fuel. The second robot $R2$ will move a little bit differently. During the first $E2$ time steps,<br> the second robot $R2$ will move to the east; then, it will move towards the north during the next $N2$ time steps. Again the second<br> robot will repeat this pattern until it runs out of fuel. If either robot moves "out of bound," it will "wrap around" and reappear<br> (by sort of magic) on the other side of the field. For example, if $M$=7 and $N$=6 and a robot at $(5,5)$ goes north, it will reappear at<br> $(5,0)$. In addition, if two robots move into the same square, they explode. Now given the starting position of the first robot at<br> (X1,Y1), and the second robot at (X2,Y2), and the amount of fuel they carry ($F1$ and $F2$), determine whether the two robots will<br> explode or not.
# Input
There is only one line of inputs that contains $M$,;$N$,;$X1$,;$Y1$,;$E1$,;$N1$,;$F1$,;$X2$,;$Y2$,;$E2$,;$N2$,;$F2$, with the following<br> constraints.
- $0<N,;M<10000$
- $0≤X1,;X2<M$
- $0≤Y1,;Y2<N$
- $(X1,Y1) is not (X2,Y2)$
- $0<N1,;E1,;N2,;E2$
- $0≤F1,;F2≤10000$
# Output
There are two cases of output. If two robots explode, output `robots explode at time T`, where T is the time they explode. Otherwise, output `robots will not explode`.
# Sample input
```
7 6 2 0 9 2 100 3 5 2 7 100
```
# Sample output
```
robots explode at time 5
```
# Testdata Set
![Testdat_Set](https://github.com/YunMunJR/judge-girl/tree/main/Loop/55.The_Robots/p55_testdata)
# Task Description
Given a convex quadrilateral Q, please determine if the origin (0,0) is with Q. For example, if Q has four corners <br>
(2,1), (−1,2), (−2,−1), and (−1,−3) then the answer is yes. If Q is (12,1), (9,2), (8,−1), and (9,−3) then the <br>
answer is no. <br>
給一個凸四邊形 Q 的四個頂點座標，請問原點 (0,0) 是否在四邊形內部，如果原點在四邊形內部，輸出 <br>
1，反之，請輸出 0。
# Input
The input consists of eight integers, a,b,c,d,e,f,g, and h, representing the four corners (a,b),(c,d),(e,f), and <br>
(g,h) in counterclockwise order. It is guaranteed that the four sides of the Q will not be parallel to either x or y axis, <br>
and will not contain the origin. The absolute value of all numbers is no more than 100. <br>
輸入包含八個整數 a,b,c,d,e,f,g,h，按照逆時針順序給定座標 (a,b),(c,d),(e,f),(g,h)。請注意：四邊形 <br>
的邊不一定平行於座標兩軸，座標的絕對值小於等於 100。
# Output
The output is either 1 or 0, representing that the origin is within or not within Q.
# Sample Input 1
2 1 -1 2 -2 -1 -1 -3
# Sample Output 1
1
# Sample Input 2
12 1 9 2 8 -1 9 -3
# Sample Output 2
0
# Hint 1
> In computational geometry of the plane, the cross product is used to determine the sign of the acute angle <br>
defined by three points p1=(
$x_1,y_1$
), p2=(
$x_2,y_2$
) and p3=(
$x_3,y_3$
). It corresponds to the direction of the <br>
cross product of the two coplanar vectors defined by the pairs of points
*p1*
,
*p2*
and 
*p1*
,
*p3*
, i.e., by the sign of <br>
the expression P=(
$x_2−x_1$
)(
$y_3−y_1$
)−(
$y_2−y_1$
)(
$x_3−x_1$
) ... (https://en.wikipedia.org/wiki/Cross_product#Computational_geometry) <br>
For sample input 1, we get four vectors
$\vec{a}$
=(2,1),
$\vec{b}$
=(−1,2),
$\vec{c}$
=(−2,−1),
$\vec{d}$
=(−1,−3).<br>
Origin in Q if and only if it must satisfy that
$\vec{a}\times\vec{b}$
=
$2\cdot2$
−
$1\cdot\(−1)$
=5>0,
$\vec{b}\times\vec{c}$
=
$(−1)\cdot\(−1)$
−
$2\cdot\(−1)$
=3>0
,
$\vec{c}\times\vec{d}$
=
$(−2)\cdot\(−3)$
−
$(−1)\cdot\(−1)$
=3>0, and
$\vec{d}\times\vec{a}$
=
$(−1)\cdot\(1)$
−
$(−3)\cdot\(2)$
=5>0
# Hint 2
(https://en.wikipedia.org/wiki/Point_in_polygon#Ray_casting_algorithm)
# Hint 3
Area summation method (Note: Be careful about arithmetic overflow)

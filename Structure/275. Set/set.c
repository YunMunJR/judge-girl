#include <stdio.h>
#include "set.h"
void init(Set* set) {
    *set = 0;
}
void add(Set* set, int i) {
    Set ans = (Set)1 << i;
    *set |= ans;
}
void has(Set set, int i) {
    Set ans = set & (Set)1 << i;
    if (ans != 0){
        printf("set has %d\n", i);
    }else{
        printf("set does not have %d\n", i);
    }
}
Set setUnion(Set a, Set b) {
    Set ans = a | b;
    return ans;
}
Set setIntersect(Set a, Set b) {
    Set ans = a & b;
    return ans;
}
Set setDifference(Set a, Set b) {
    Set ans1= a | b; Set ans2 = a & b;
    Set ans = ans1 & (~ans2);
    return ans;
}
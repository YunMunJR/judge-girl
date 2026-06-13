#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
 
static char *eptr = NULL;
static int peek() {
    while (isspace(*eptr))
        eptr++;
    return eptr[0];
}
static void fetch(char c) {
    assert(peek() == c);
    eptr++;
}
static double parser() {
    char c = peek();
    double p, a, b, ret;
    if (c == '(') {
        fetch('(');
        p = parser();
        a = parser();
        b = parser();
        fetch(')');
        ret = p * (a + b) + (1.f - p) * (a - b);
    } else {
        sscanf(eptr, "%lf", &ret);
        while (isdigit(*eptr) || *eptr == '.' || *eptr == '-')
            eptr++;
    }
    return ret;
}
int main() {
    char s[1024];
    while (gets(s)) {
        eptr = s;
        printf("%.2lf\n", parser());
    }
    return 0;
}
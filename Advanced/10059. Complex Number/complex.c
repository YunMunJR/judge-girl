#include <stdio.h>
#include "complex.h"
void init(complex* c, float a, float b) {
    c->real = a; c->imag = b;
}
void complex_print(complex* x) {
    float a, b;
    a = x->real; b = x->imag;
    printf("%.3f%+.3fi\n", a, b);
}
complex complex_add(complex* x, complex* y) {
    complex ans;
    ans.real = x->real + y->real; ans.imag = x->imag + y->imag;
    return ans;
}
complex complex_sub(complex* x, complex* y) {
    complex ans;
    ans.real = x->real - y->real; ans.imag = x->imag - y->imag;
    return ans;
}
complex complex_mul(complex* x, complex* y) {
    complex ans;
    ans.real = x->real * y->real - x->imag * y->imag; 
    ans.imag = x->real * y->imag + x->imag * y->real;
    return ans;
}
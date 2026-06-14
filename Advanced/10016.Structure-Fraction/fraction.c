#include "fraction.h"

long long gcd(long long a, long long b)
{
    if(a < 0) a = -a;
    if(b < 0) b = -b;

    while(b){
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

Frac normal(long long a, long long b)
{
    if(b < 0){
        a = -a;
        b = -b;
    }

    long long g = gcd(a, b);

    Frac r;
    r.a = a / g;
    r.b = b / g;

    return r;
}

Frac add(Frac x, Frac y)
{
    return normal(
        x.a * y.b + y.a * x.b,
        x.b * y.b
    );
}

Frac subtract(Frac x, Frac y)
{
    return normal(
        x.a * y.b - y.a * x.b,
        x.b * y.b
    );
}

Frac multipy(Frac x, Frac y)
{
    return normal(
        x.a * y.a,
        x.b * y.b
    );
}

Frac divide(Frac x, Frac y)
{
    return normal(
        x.a * y.b,
        x.b * y.a
    );
}
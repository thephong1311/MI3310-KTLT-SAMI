#include<iostream>
#include "function.h"

double get_pow(double x, int y) {
    double res;
    if(y == 0) return 1.0;
    if(y == 1) return x;
    res = get_pow(x, y/2);
    res = res*res;
    if(y%2) res = res*x;
    return res;
}

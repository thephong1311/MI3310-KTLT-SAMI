#include<iostream>
#include "function.h"

void iterative(double *x, double *x_old, double **G, double *c) {
    double res;
    for(int j = 0;j < n;j++)
        x_old[j] = x[j];
    for(int i = 0;i < n;i++) {
        res = 0.0;
        for(int j = 0;j < n;j++)
            res = res + G[i][j]*x_old[j];
        x[i] = res + c[i];
    }
}

void iterative_seidel(double *x, double *x_old, double **G, double *c) {
    double res;
    for(int j = 0;j < n;j++)
        x_old[j] = x[j];
    for(int i = 0;i < n;i++) {
        res = 0.0;
        for(int j = 0;j < n;j++)
            res = res + G[i][j]*x[j];
        x[i] = res + c[i];
    }
}

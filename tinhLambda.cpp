#include<iostream>
#include<math.h>
#include "function.h"

using namespace std;

double get_lambda_row(double **G) {
    double res = 0.0, left, right;
    for(int i = 0;i < n;i++) {
        left = 0;
        right = 0;
        for(int j = 0;j < i;j++)
            left = left + fabs(G[i][j]);
        for(int j = i;j < n;j++)
            right = right + fabs(G[i][j]);

        res = max(res, right/(1-left));
    }
    return res;
}

double get_lambda_col(double **G) {
    double res = 0.0, left, right;
    for(int j = 0;j < n;j++) {
        left = 0;
        right = 0;
        for(int i = 0;i <= j;i++)
            left = left + fabs(G[i][j]);
        for(int i = j+1;i < n;i++)
            right = right + fabs(G[i][j]);

        res = max(res, left/(1-right));
    }
    return res;
}

double get_s(double **G) {
    double res = 0.0, temp;
    for(int j = 0;j < n;j++) {
        temp = 0;
        for(int i = j+1;i < n;i++)
            temp = temp + fabs(G[i][j]);

        res = max(res, temp);
    }
    return res;
}

double get_frac(double **A) {
    double res;
    double mx = 0, mn = 1e9*1.0;
    for(int i = 0;i < n;i++) {
        mx = max(mx, fabs(A[i][i]));
        mn = min(mx, fabs(A[i][i]));
    }
    res = mx/mn;
    return res;
}

#include<iostream>
#include<math.h>
#include "function.h"

using namespace std;

double vector_norm_row(double *temp) {
    double res = 0.0;
    for(int i = 0;i < n;i++)
        res = max(res, fabs(temp[i]));
    return res;
}

double vector_norm_col(double *temp) {
    double res = 0.0;
    for(int i = 0;i < n;i++)
        res = res + fabs(temp[i]);
    return res;
}

double matrix_norm_row(double **temp) {
    double res, sum_row;
    res = 0.0;

    for(int i = 0;i < n;i++) {
        sum_row = 0.0;
        for(int j = 0;j < n;j++)
            sum_row = sum_row + fabs(temp[i][j]);
        res = max(res, sum_row);
    }
    return res;
}

double matrix_norm_col(double **temp) {
    double res, sum_col;
    res = 0.0;

    for(int j = 0;j < n;j++) {
        sum_col = 0.0;
        for(int i = 0;i < n;i++)
            sum_col = sum_col + fabs(temp[i][j]);
        res = max(res, sum_col);
    }
    return res;
}

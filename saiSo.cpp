#include<iostream>
#include "function.h"

// row
double relative_error_row(double *x, double *x_old) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++)
        temp[i] = x[i] - x_old[i];
    res = vector_norm_row(temp)/vector_norm_row(x);
    return res;
}

double absolute_error_row(double *x, double *x_old) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++)
        temp[i] = x[i] - x_old[i];
    res = vector_norm_row(temp);
    return res;
}

double absolute_error_pos_row_not_seidel(double *x, double *x_old, double norm_G) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++)
        temp[i] = x[i] - x_old[i];
    res = vector_norm_row(temp)*norm_G/(1-norm_G);
    return res;
}

double absolute_error_pre_row_not_seidel(double *x_fi, int k, double norm_G) {
    double res;
    res = vector_norm_row(x_fi)*get_pow(norm_G, k)/(1-norm_G);
    return res;
}

double absolute_error_pos_row_seidel(double *x, double *x_old, double lambda) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++)
        temp[i] = x[i] - x_old[i];
    res = vector_norm_row(temp)*lambda/(1-lambda);
    return res;
}

double absolute_error_pre_row_seidel(double *x_fi, int k, double lambda) {
    double res = vector_norm_row(x_fi)*get_pow(lambda, k)/(1-lambda);
    return res;
}

// column
double relative_error_col(double *x, double *x_old) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++)
        temp[i] = x[i] - x_old[i];
    res = vector_norm_col(temp)/vector_norm_col(x);
    return res;
}

double absolute_error_col(double *x, double *x_old) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++)
        temp[i] = x[i] - x_old[i];
    res = vector_norm_col(temp);
    return res;
}
double absolute_error_pos_col_not_seidel(double *x, double *x_old, double frac, double norm_G_col) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++)
        temp[i] = x[i] - x_old[i];
    res = frac*vector_norm_col(temp)*norm_G_col/(1-norm_G_col);
    return res;
}

double absolute_error_pre_col_not_seidel(double *x_fi, int k, double frac, double norm_G_col) {
    double res;
    res = frac*vector_norm_col(x_fi)*get_pow(norm_G_col, k)/(1-norm_G_col);
    return res;
}

double absolute_error_pos_col_seidel(double *x, double *x_old, double s, double lambda) {
    double res;
    double *temp = new double[n+1];
    for(int i = 0;i < n;i++)
        temp[i] = x[i] - x_old[i];
    res = (1-s)*vector_norm_col(temp)*lambda/(1-lambda);
    return res;
}

double absolute_error_pre_col_seidel(double *x_fi, int k, double s, double lambda) {
    double res;
    res = (1-s)*vector_norm_col(x_fi)*get_pow(lambda, k)/(1-lambda);
    return res;
}





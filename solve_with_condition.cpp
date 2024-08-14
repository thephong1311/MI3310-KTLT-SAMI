#include<iostream>
#include<iomanip>
#include "function.h"

using namespace std;

void solve_iterative_method_row_th(double **G, double *c, double epsilon) {
    double *x, *x_old;
    double error;
    int k = 0;

    // Cấp phát bộ nhớ cho x, x_old
    x = new double[n+1];
    x_old = new double[n+1];

    // Đặt nghiệm ban đầu x = 0
    for(int i = 0;i < n;i++)
        x[i] = 0;

    // Thực hiện lặp
    while(true) {
        k = k + 1;

        // Áp dụng công thức lặp Jacobi
        iterative(x, x_old, G, c);

        // Điều kiện dừng
        error = absolute_error_row(x, x_old);
        if(error < epsilon)
            break;
    }
    // In kết quả
    cout << "\t\tSố lần lặp: " << k << endl;
    cout << fixed << setprecision(precision) << "\t\tSai số tuyệt đối: " << absolute_error_row(x, x_old) << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}

void solve_iterative_seidel_method_row_th(double **G, double *c, double epsilon) {
    double *x, *x_old;
    double error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];

    for(int i = 0;i < n;i++)
        x[i] = 0;

    while(true) {
        k = k + 1;

        iterative_seidel(x, x_old, G, c);

        error = absolute_error_row(x, x_old);
        if(error < epsilon)
            break;
    }
    cout << "\t\tSố lần lặp: " << k << endl;
    cout << fixed << setprecision(precision) << "\t\tSai số tuyệt đối: " << absolute_error_row(x, x_old) << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}

void solve_iterative_method_col_th(double **G, double *c, double epsilon) {
    double *x, *x_old;
    double error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];

    for(int i = 0;i < n;i++)
        x[i] = 0;

    while(true) {
        k = k + 1;

        iterative(x, x_old, G, c);

        error = absolute_error_col(x, x_old);
        if(error < epsilon)
            break;
    }
    cout << "\t\tSố lần lặp: " << k << endl;
    cout << fixed << setprecision(precision) << "\t\tSai số tuyệt đối: " << absolute_error_col(x, x_old) << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}

void solve_iterative_seidel_method_col_th(double **G, double *c, double epsilon) {
    double *x, *x_old;
    double error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];

    for(int i = 0;i < n;i++)
        x[i] = 0;

    while(true) {
        k = k + 1;

        iterative_seidel(x, x_old, G, c);

        error = absolute_error_col(x, x_old);
        if(error < epsilon)
            break;
    }
    cout << "\t\tSố lần lặp: " << k << endl;
    cout << fixed << setprecision(precision) << "\t\tSai số tuyệt đối: " << absolute_error_col(x, x_old) << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}



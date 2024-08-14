#include<iostream>
#include<iomanip>
#include "function.h"

using namespace std;

string statement_fi[2] = {"\t\tSai số tuyệt đối hậu nghiệm: ", "\t\tSai số tuyệt đối tiên nghiệm: "};

void solve_iterative_method_row_fi(double **G, double *c, int k, int type) {
    double *x, *x_old, *x_fi;
    double norm_G, error;
    int temp;

    // Cấp phát bộ nhớ cho x, x_old, x_fi
    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    // Đặt nghiệm ban đầu x = 0
    for(int i = 0;i < n;i++)
        x[i] = 0;

    // Tính chuẩn hàng của G
    norm_G = matrix_norm_row(G);

    // Thực hiện lặp
    temp = k;
    while(temp > 0) {
        temp = temp - 1;

        // Áp dụng công thức lặp Jacobi
        iterative(x, x_old, G, c);

        if(k-temp == 1)
            for(int i = 0;i < n;i++)
                x_fi[i] = x[i];
    }

    // Chọn loại sai số
    if(type == 1)
        error = absolute_error_pos_row_not_seidel(x, x_old, norm_G); // Sai số tuyệt đối hậu nghiệm
    else if(type == 2)
        error = absolute_error_pre_row_not_seidel(x_fi, k, norm_G); // Sai số tuyệt đối tiên nghiệm

    // In kết quả
    cout << fixed << statement_fi[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}

void solve_iterative_seidel_method_row_fi(double **G, double *c, int k, int type) {
    double *x, *x_old, *x_fi;
    double lambda, error;
    int temp;
    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    for(int i = 0;i < n;i++)
        x[i] = 0;

    lambda = get_lambda_row(G);

    temp = k;
    while(temp > 0) {
        temp = temp - 1;

        iterative_seidel(x, x_old, G, c);

        if(k-temp == 1)
            for(int i = 0;i < n;i++)
                x_fi[i] = x[i];
    }

    if(type == 1)
        error = absolute_error_pos_row_seidel(x, x_old, lambda); // Sai số tuyệt đối hậu nghiệm
    else if(type == 2)
        error = absolute_error_pre_row_seidel(x_fi, k, lambda); // Sai số tuyệt đối tiên nghiệm

    cout << fixed << statement_fi[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}

void solve_iterative_method_col_fi(double **G, double *c, double **G_col, double frac, int k, int type) {
    double *x, *x_old, *x_fi;
    double norm_G_col, error;
    int temp = k;
    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    for(int i = 0;i < n;i++)
        x[i] = 0;

    norm_G_col = matrix_norm_col(G_col);

    temp = k;
    while(temp > 0) {
        temp = temp - 1;

        iterative(x, x_old, G, c);

        if(k-temp == 1)
            for(int i = 0;i < n;i++)
                x_fi[i] = x[i];
    }

    if(type == 1)
        error = absolute_error_pos_col_not_seidel(x, x_old, frac, norm_G_col); // Sai số tuyệt đối hậu nghiệm
    else if(type == 2)
        error = absolute_error_pre_col_not_seidel(x_fi, k, frac, norm_G_col); // Sai số tuyệt đối tiên nghiệm
    cout << fixed << statement_fi[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}

void solve_iterative_seidel_method_col_fi(double **G, double *c, double **G_col, int k, int type) {
    double *x, *x_old, *x_fi;
    double lambda, s, error;
    int temp;

    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    for(int i = 0;i < n;i++)
        x[i] = 0;

    lambda = get_lambda_col(G_col);
    s = get_s(G_col);

    temp = k;
    while(temp > 0) {
        temp = temp - 1;

        iterative_seidel(x, x_old, G, c);

        if(k-temp == 1)
            for(int i = 0;i < n;i++)
                x_fi[i] = x[i];
    }

    if(type == 1)
        error = absolute_error_pos_col_seidel(x, x_old, s, lambda); // Sai số tuyệt đối hậu nghiệm
    else if(type == 2)
        error = absolute_error_pre_col_seidel(x_fi, k, s, lambda); // Sai số tuyệt đối tiên nghiệm

    cout << fixed << statement_fi[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}

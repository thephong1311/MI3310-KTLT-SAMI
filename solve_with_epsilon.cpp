#include<iostream>
#include<iomanip>
#include "function.h"

using namespace std;

string statement_se[2] = {"\t\tSai số tuyệt đối hậu nghiệm: ", "\t\tSai số tuyệt đối tiên nghiệm: "};

void solve_iterative_method_row_se(double **G, double *c, double epsilon, int type) {
    double *x, *x_old, *x_fi;
    double norm_G, error;
    int k = 0;

    // Cấp phát bộ nhớ cho x, x_old, x_fi
    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    // Đặt nghiệm ban đầu x = 0
    for(int i = 0;i < n;i++)
        x[i] = 0;

    // Tính chuẩn hàng của ma trận G
    norm_G = matrix_norm_row(G);

    // Thực hiện lặp
    while(true) {
        k = k + 1;

        // Áp dụng công thức lặp Jacobi
        iterative(x, x_old, G, c);

        // Lưu sai số lần lặp đầu
        if(k == 1)
            for(int i = 0;i < n;i++)
                x_fi[i] = x[i];

        // Xác định sai số
        if(type == 1)
            error = absolute_error_pos_row_not_seidel(x, x_old, norm_G); // Sai số tuyệt đối hậu nghiệm
        else if(type == 2)
            error = absolute_error_pre_row_not_seidel(x_fi, k, norm_G); // Sai số tuyệt đối tiên nghiệm

        // Điều kiên dừng
        if(error < epsilon)
            break;
    }

    // In kết quả
    cout << "\t\tSố lần lặp: " << k << endl;
    cout << fixed << statement_se[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}

void solve_iterative_seidel_method_row_se(double **G, double *c, double epsilon, int type) {
    double *x, *x_old, *x_fi;
    double lambda, error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    for(int i = 0;i < n;i++)
        x[i] = 0;

    lambda = get_lambda_row(G);

    while(true) {
        k = k + 1;

        iterative_seidel(x, x_old, G, c);

        if(k == 1)
            for(int i = 0;i < n;i++)
                x_fi[i] = x[i];

        if(type == 1)
            error = absolute_error_pos_row_seidel(x, x_old, lambda); // Sai số tuyệt đối hậu nghiệm
        else if(type == 2)
            error = absolute_error_pre_row_seidel(x_fi, k, lambda); // Sai số tuyệt đối tiên nghiệm

        if(error < epsilon)
            break;
    }
    cout << "\t\tSố lần lặp: " << k << endl;
    cout << fixed << statement_se[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}

void solve_iterative_method_col_se(double **G, double *c, double **G_col, double epsilon, double frac, int type) {
    double *x, *x_old, *x_fi;
    double norm_G_col, error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    for(int i = 0;i < n;i++)
        x[i] = 0;

    norm_G_col = matrix_norm_col(G_col);

    while(true) {
        k = k + 1;

        iterative(x, x_old, G, c);

        if(k == 1)
            for(int i = 0;i < n;i++)
                x_fi[i] = x[i];

        if(type == 1)
            error = absolute_error_pos_col_not_seidel(x, x_old, frac, norm_G_col); // Sai số tuyệt đối hậu nghiệm
        else if(type == 2)
            error = absolute_error_pre_col_not_seidel(x_fi, k, frac, norm_G_col); // Sai số tuyệt đối tiên nghiệm

        if(error < epsilon)
            break;
    }
    cout << "\t\tSố lần lặp: " << k << endl;
    cout << fixed << statement_se[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}

void solve_iterative_seidel_method_col_se(double **G, double *c, double **G_col, double epsilon, int type) {
    double *x, *x_old, *x_fi;
    double lambda, s, error;
    int k = 0;
    x = new double[n+1];
    x_old = new double[n+1];
    x_fi = new double[n+1];

    for(int i = 0;i < n;i++)
        x[i] = 0;

    lambda = get_lambda_col(G_col);
    s = get_s(G_col);

    while(true) {
        k = k + 1;

        iterative_seidel(x, x_old, G, c);

        if(k == 1)
            for(int i = 0;i < n;i++)
                x_fi[i] = x[i];

        if(type == 1)
            error = absolute_error_pos_col_seidel(x, x_old, s, lambda); // Sai số tuyệt đối hậu nghiệm
        else if(type == 2)
            error = absolute_error_pre_col_seidel(x_fi, k, s, lambda); // Sai số tuyệt đối tiên nghiệm

        if(error < epsilon)
            break;
    }
    cout << "\t\tSố lần lặp: " << k << endl;
    cout << fixed << statement_se[type-1] << setprecision(precision) << error << endl;
    cout << "\t\tNghiệm của hệ phương trình: \n";
    print_vector(x);
}

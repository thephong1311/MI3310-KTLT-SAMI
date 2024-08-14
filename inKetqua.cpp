#include<iostream>
#include<iomanip>
#include "function.h"

using namespace std;

void print_matrix(double **temp) {
    cout << fixed;
    for(int i = 0;i < n;i++) {
        cout << "\t\t";
        for(int j = 0;j < n;j++)
            cout << setw(precision + 5) << setprecision(precision) << temp[i][j] << ' ';
        cout << endl;
    }
}

void print_vector(double *temp) {
    cout << fixed;
    for(int i = 0;i < n;i++)
        cout << "\t\t| x_" << i+1 << ": " << setw(precision) << setprecision(precision) << temp[i] << "\n";
    cout << endl;
}

#include<iostream>
#include<math.h>
#include "function.h"

using namespace std;

bool row_diag_dom(double **temp) {
    double sum_row;

    for(int i = 0;i < n;i++) {
        sum_row = 0.0;
        for(int j = 0;j < n;j++)
            sum_row = sum_row + fabs(temp[i][j]);
        sum_row = sum_row - fabs(temp[i][i]);
        if(fabs(temp[i][i]) < sum_row)
            return false;
    }
    return true;
}

bool col_diag_dom(double **temp) {
    double sum_col;

    for(int j = 0;j < n;j++) {
        sum_col = 0.0;
        for(int i = 0;i < n;i++)
            sum_col = sum_col + fabs(temp[i][j]);
        sum_col = sum_col - fabs(temp[j][j]);
        if(fabs(temp[j][j]) < sum_col)
            return false;
    }
    return true;
}

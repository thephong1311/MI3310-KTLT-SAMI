#include<iostream>
#include "function.h"

void getGc(double **G, double *c, double **A, double *b) {
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            if(i == j)  G[i][j] = 0;
            else G[i][j] = -A[i][j]/A[i][i];

    for(int i = 0;i < n;i++)
        c[i] = b[i]/A[i][i];
}

void getG_col(double **G_col, double **A, double *b) {
    for(int j = 0;j < n;j++)
        for(int i = 0;i < n;i++)
            if(i == j) G_col[j][j] = 0;
            else G_col[i][j] = -A[i][j]/A[j][j];
}

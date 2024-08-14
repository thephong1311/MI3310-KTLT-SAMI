#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

extern int precision;
extern int n, k;
extern double **A, **G, **G_col;
extern double *b, *c;
extern double epsilon, frac;

void setcolor(int color);
void setting_console();
void note();
void submenu_input();
void submenu_se(int mode);
void border(int w);
void solve(int mode);


double get_pow(double x, int y);
void print_matrix(double **temp);
void print_vector(double *temp);

bool row_diag_dom(double **temp);
bool col_diag_dom(double **temp);

double vector_norm_row(double *temp);
double vector_norm_col(double *temp);
double matrix_norm_row(double **temp);
double matrix_norm_col(double **temp);

double relative_error_row(double *x, double *x_old);
double absolute_error_row(double *x, double *x_old);
double absolute_error_pos_row_not_seidel(double *x, double *x_old, double norm_G);
double absolute_error_pre_row_not_seidel(double *x_fi, int k, double norm_G);
double absolute_error_pos_row_seidel(double *x, double *x_old, double lambda);
double absolute_error_pre_row_seidel(double *x_fi, int k, double lambda);

double relative_error_col(double *x, double *x_old);
double absolute_error_col(double *x, double *x_old);
double absolute_error_pos_col_not_seidel(double *x, double *x_old, double frac, double norm_G_col);
double absolute_error_pre_col_not_seidel(double *x_fi, int k, double frac, double norm_G_col);
double absolute_error_pos_col_seidel(double *x, double *x_old, double s, double lambda);
double absolute_error_pre_col_seidel(double *x_fi, int k, double s, double lambda);

double get_lambda_row(double **G);
double get_lambda_col(double **G);
double get_s(double **G);
void getGc(double **G, double *c, double **A, double *b);
void getG_col(double **G_col, double **A, double *b);
double get_frac(double **A);

void iterative(double *x, double *x_old, double **G, double *c);
void iterative_seidel(double *x, double *x_old, double **G, double *c);

void solve_iterative_method_row_se(double **G, double *c, double epsilon, int type);
void solve_iterative_seidel_method_row_se(double **G, double *c, double epsilon, int type);
void solve_iterative_method_col_se(double **G, double *c, double **G_col, double epsilon, double frac, int type);
void solve_iterative_seidel_method_col_se(double **G, double *c, double **G_col, double epsilon, int type);

void solve_iterative_method_row_th(double **G, double *c, double epsilon);
void solve_iterative_seidel_method_row_th(double **G, double *c, double epsilon);
void solve_iterative_method_col_th(double **G, double *c, double epsilon);
void solve_iterative_seidel_method_col_th(double **G, double *c, double epsilon);

void solve_iterative_method_row_fi(double **G, double *c, int k, int type);
void solve_iterative_seidel_method_row_fi(double **G, double *c, int k, int type);
void solve_iterative_method_col_fi(double **G, double *c, double **G_col, double frac, int k, int type);
void solve_iterative_seidel_method_col_fi(double **G, double *c, double **G_col, int k, int type);

#endif // FUNCTION_H_INCLUDED

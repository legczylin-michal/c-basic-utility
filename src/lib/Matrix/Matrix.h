#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "../types.h"

Matrix new_Matrix(size_t rows, size_t cols);
void del_Matrix(Matrix *self);
Matrix copy_Matrix(Matrix self);
String str_Matrix(Matrix self);

Matrix Matrix_Zeros(size_t rows, size_t cols);
Matrix Matrix_Ones(size_t rows, size_t cols);
Matrix Matrix_Fill(size_t rows, size_t cols, double value);

Matrix Matrix_Identity(size_t rows, size_t cols);

Matrix Matrix_From_1D(size_t rows, size_t cols, double *values);
Matrix Matrix_From_2D(size_t rows, size_t cols, double **values);

size_t Matrix_GetRows(Matrix self);
size_t Matrix_GetCols(Matrix self);

double Matrix_Get(Matrix self, int row, int col);
void Matrix_Set(Matrix self, int row, int col, double value);

Matrix Matrix_Sum(Matrix A, Matrix B);
Matrix Matrix_Difference(Matrix A, Matrix B);
Matrix Matrix_Product(Matrix A, Matrix B);
Matrix Matrix_DOT(Matrix A, Matrix B);

Matrix Matrix_PLU_Decomposition(Matrix A);

double Matrix_Determinant(Matrix self);

#endif // !_MATRIX_H_
#include "Matrix.h"

#include "../String/String.h"

#define ECHO printf("In %s::%d in function %s\n", __FILE__, __LINE__, __FUNCTION__)

struct cMatrix
{
    size_t _rows;
    size_t _cols;
    size_t _size;
    double *_values;
};

size_t pos2idx(Matrix self, size_t row, size_t col)
{
    return row * self->_cols + col;
}

void idx2pos(Matrix self, size_t index, size_t *row, size_t *col)
{
    *row = index / self->_cols;
    *col = index - (*row) * self->_cols;

    return;
}

void posInt2posSizeT(Matrix self, int rowInt, int colInt, size_t *rowSizeT, size_t *colSizeT)
{
    if (rowInt < 0)
        *rowSizeT = self->_rows - (-rowInt) % self->_rows;
    else
        *rowSizeT = rowInt % self->_rows;

    if (colInt < 0)
        *colSizeT = self->_cols - (-colInt) % self->_cols;
    else
        *colSizeT = colInt % self->_cols;

    return;
}

Matrix new_Matrix(size_t rows, size_t cols)
{
    Matrix result = (Matrix)malloc(sizeof(struct cMatrix));

    result->_rows = rows;
    result->_cols = cols;
    result->_size = result->_rows * result->_cols;
    result->_values = (double *)malloc(sizeof(double) * result->_size);
    for (size_t i = 0; i < result->_size; i++)
        result->_values[i] = 0.0f;

    return result;
}

void del_Matrix(Matrix *self)
{
    if ((*self) == NULL)
        return;

    free((*self)->_values);
    free(*self);

    *self = NULL;

    return;
}

Matrix copy_Matrix(Matrix self)
{
    Matrix result = new_Matrix(self->_rows, self->_cols);

    for (size_t i = 0; i < result->_size; i++)
        result->_values[i] = self->_values[i];

    return result;
}

String str_Matrix(Matrix self)
{
    String result = str("Matrix(");

    String tmp = str(self->_rows);
    String_Append(result, tmp);
    del_String(&tmp);

    tmp = str("x");
    String_Append(result, tmp);
    del_String(&tmp);

    tmp = str(self->_cols);
    String_Append(result, tmp);
    del_String(&tmp);

    tmp = str(") [\n");
    String_Append(result, tmp);
    del_String(&tmp);

    for (size_t row = 0; row < Matrix_GetRows(self); row++)
    {
        tmp = str("\t[");
        String_Append(result, tmp);
        del_String(&tmp);
        for (size_t col = 0; col < Matrix_GetCols(self); col++)
        {
            tmp = str(Matrix_Get(self, row, col));
            String_Append(result, tmp);
            del_String(&tmp);
            tmp = str(", ");
            String_Append(result, tmp);
            del_String(&tmp);
        }
        tmp = str("]\n");
        String_Append(result, tmp);
        del_String(&tmp);
    }
    tmp = str("]");
    String_Append(result, tmp);
    del_String(&tmp);

    return result;
}

Matrix Matrix_Zeros(size_t rows, size_t cols)
{
    return new_Matrix(rows, cols);
}

Matrix Matrix_Ones(size_t rows, size_t cols)
{
    return Matrix_Fill(rows, cols, 1.0f);
}

Matrix Matrix_Fill(size_t rows, size_t cols, double value)
{
    Matrix result = new_Matrix(rows, cols);

    for (size_t i = 0; i < result->_size; i++)
        result->_values[i] = value;

    return result;
}

Matrix Matrix_Identity(size_t rows, size_t cols)
{
    Matrix result = new_Matrix(rows, cols);

    size_t dim = rows < cols ? rows : cols;

    for (size_t i = 0; i < dim; i++)
        Matrix_Set(result, i, i, 1.0f);

    return result;
}

Matrix Matrix_From_1D(size_t rows, size_t cols, double *values)
{
    Matrix result = new_Matrix(rows, cols);

    for (size_t i = 0; i < result->_size; i++)
        result->_values[i] = values[i];

    return result;
}

Matrix Matrix_From_2D(size_t rows, size_t cols, double **values)
{
    Matrix result = new_Matrix(rows, cols);

    for (size_t row = 0; row < rows; row++)
        for (size_t col = 0; col < cols; col++)
            Matrix_Set(result, row, col, values[row][col]);

    return result;
}

size_t Matrix_GetRows(Matrix self)
{
    return self->_rows;
}

size_t Matrix_GetCols(Matrix self)
{
    return self->_cols;
}

double Matrix_Get(Matrix self, int row, int col)
{
    size_t rowSizeT, colSizeT;

    posInt2posSizeT(self, row, col, &rowSizeT, &colSizeT);

    return self->_values[pos2idx(self, rowSizeT, colSizeT)];
}

void Matrix_Set(Matrix self, int row, int col, double value)
{
    size_t rowSizeT, colSizeT;

    posInt2posSizeT(self, row, col, &rowSizeT, &colSizeT);

    self->_values[pos2idx(self, rowSizeT, colSizeT)] = value;

    return;
}

Matrix Matrix_Sum(Matrix A, Matrix B)
{
    if (!(A->_rows == B->_rows && A->_cols == B->_cols))
    {
        exit(-1);
    }

    Matrix result = new_Matrix(A->_rows, A->_cols);

    for (size_t i = 0; i < A->_size; i++)
        result->_values[i] = A->_values[i] + B->_values[i];

    return result;
}

Matrix Matrix_Difference(Matrix A, Matrix B)
{
    if (!(A->_rows == B->_rows && A->_cols == B->_cols))
    {
        exit(-1);
    }

    Matrix result = new_Matrix(A->_rows, A->_cols);

    for (size_t i = 0; i < A->_size; i++)
        result->_values[i] = A->_values[i] - B->_values[i];

    return result;
}

Matrix Matrix_Product(Matrix A, Matrix B)
{
    if (!(A->_rows == B->_rows && A->_cols == B->_cols))
    {
        exit(-1);
    }

    Matrix result = new_Matrix(A->_rows, A->_cols);

    for (size_t i = 0; i < A->_size; i++)
        result->_values[i] = A->_values[i] * B->_values[i];

    return result;
}

Matrix Matrix_DOT(Matrix A, Matrix B)
{
    if (!(A->_cols == B->_rows))
    {
        exit(-1);
    }

    Matrix result = new_Matrix(A->_rows, B->_cols);

    for (size_t row = 0; row < result->_rows; row++)
        for (size_t col = 0; col < result->_cols; col++)
            for (size_t k = 0; k < A->_cols; k++)
                Matrix_Set(result, row, col, Matrix_Get(result, row, col) + Matrix_Get(A, row, k) * Matrix_Get(B, k, col));

    return result;
}

Matrix Matrix_PLU_Decomposition(Matrix A)
{
    Matrix result = new_Matrix(A->_rows, A->_cols);

    for (int row = 0; row < result->_rows; row++)
    {
        // L
        for (int col = 0; col < row; col++)
        {
            Matrix_Set(result, row, col, Matrix_Get(A, row, col));

            for (int k = 0; k < col; k++)
            {
                Matrix_Set(result, row, col, Matrix_Get(result, row, col) - Matrix_Get(result, row, k) * Matrix_Get(result, k, col));
            }

            Matrix_Set(result, row, col, Matrix_Get(result, row, col) / Matrix_Get(result, col, col));
        }
        // U
        for (int col = row; col < result->_cols; col++)
        {
            Matrix_Set(result, row, col, Matrix_Get(A, row, col));

            for (int k = 0; k < row; k++)
            {
                Matrix_Set(result, row, col, Matrix_Get(result, row, col) - Matrix_Get(result, row, k) * Matrix_Get(result, k, col));
            }
        }
    }

    return result;
}

double Matrix_Determinant(Matrix self)
{
    Matrix LU = Matrix_PLU_Decomposition(self);
    String m_str_repr = str_Matrix(LU);
    printf("%s\n", String_GetCharacters(m_str_repr));
    del_String(&m_str_repr);

    double det = 1.0;

    for (size_t i = 0; i < LU->_rows; i++)
    {
        det *= Matrix_Get(LU, i, i);
    }

    del_Matrix(&LU);

    return det;
}
#include <stdio.h>

#include "../lib/Matrix/Matrix.h"
#include "../lib/String/String.h"

void experiment(Matrix m, const char *title)
{
    String m_str_repr = str_Matrix(m);
    printf("%s:\n%s\n", title, String_GetCharacters(m_str_repr));
    del_String(&m_str_repr);
    printf("det=%lf\n\n", Matrix_Determinant(m));
}

int main(int argc, char const *argv[])
{
    Matrix m1 = Matrix_Fill(3, 3, 2.0f);
    experiment(m1, "M1 fill");

    Matrix m2 = Matrix_From_1D(3, 3, (double[]){1, 2, 3, 4, 5, 6, 7, 8, 9});
    experiment(m2, "M2 from 1D");

    double *data[] = {
        (double[]){10, 18, 15},
        (double[]){16, 13, 11},
        (double[]){17, 12, 14},
    };
    Matrix m3 = Matrix_From_2D(3, 3, data);
    experiment(m3, "M3 from 2D");

    Matrix m4 = Matrix_Sum(m1, m2);
    experiment(m4, "M4 = M1 + M2");

    Matrix m5 = Matrix_Difference(m2, m3);
    experiment(m5, "M5 = M2 - M3");

    Matrix m6 = Matrix_Product(m1, m3);
    experiment(m6, "M6 = M1 * M3");

    Matrix m7 = Matrix_DOT(m1, m3);
    experiment(m7, "M7 = M1 @ M3");

    del_Matrix(&m7);
    del_Matrix(&m6);
    del_Matrix(&m5);
    del_Matrix(&m4);
    del_Matrix(&m3);
    del_Matrix(&m2);
    del_Matrix(&m1);

    printf("\nCOMPILED SUCCESSFULLY\n");

    return 0;
}
#include <rc/r_types.h>
#include <rc/r_matrix.h>

RMatrix *r_create_matrix(size_t cols, size_t rows)
{
    RMatrix *matrix = malloc(sizeof(RMatrix));

    matrix->cols = cols;
    matrix->rows = rows;
    matrix->data = malloc(sizeof(float) * matrix->cols * matrix->rows);

    return matrix;
}

void r_free_matrix(RNONNULL RMatrix *matrix)
{
    free(matrix->data);
    matrix->cols = 0;
    matrix->rows = 0;
    free(matrix);
}

RMatrix *r_mat_mul(const RNONNULL RMatrix *mat1, const RNONNULL RMatrix *mat2)
{
    if (mat1->cols != mat2->cols || mat1->rows != mat2->rows)
    {
        printf("[ERROR]: Matrices size has to be the same to perform this operation\n");
        return NULL;
    }

    RMatrix *result = malloc(sizeof(RMatrix));
    result->cols = mat1->cols;
    result->rows = mat2->rows;
    result->data = malloc(sizeof(float) * result->cols * result->rows);

    for (int i = 0; i < mat1->rows; i++)
        for (int j = 0; j < mat2->cols; j++)
        {
            float sum = 0.0f;
            for (int k = 0; k < mat1->rows; k++)
            {
                sum += mat1->data[RMatrixIDX(i, k, mat1->cols)] * mat2->data[RMatrixIDX(i, k, mat2->cols)];
            }
            result->data[RMatrixIDX(i, j, result->cols)] = sum;
        }
    return result;
}

RMatrix *transpose(const RNONNULL RMatrix *matrix)
{
    RMatrix *transposed_matrix = r_create_matrix(matrix->cols, matrix->rows);
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            transposed_matrix->data[RMatrixIDX(i, j, transposed_matrix->cols)] = matrix->data[RMatrixIDX(i, j, matrix->cols)];
        }
    }
    return transposed_matrix;
}

void r_print_matrix(RNONNULL RMatrix *m, const RNONNULL char *name)
{
    printf("%s (%dx%d):\n", name, m->rows, m->cols);
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            printf("%.2f ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}
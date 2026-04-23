#include <rc/r_types.h>
#include <rc/r_matrix.h>

float r_cross_entropy(const RNONNULL RMatrix *matrix, const RNONNULL RMatrix *src)
{
    float total = 0.0f;

    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->cols; j++)
        {
            float prediction = matrix->data[RMatrixIDX(i, j, matrix->cols)];
            float correct = src->data[RMatrixIDX(i, j, src->cols)];
            total += correct * log(prediction + EPSILON);
        }
    }

    return -total/src->rows;
}

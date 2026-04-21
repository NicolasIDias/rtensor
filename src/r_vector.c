#include <rc/r_types.h>
#include <rc/r_matrix.h>
#include <rc/r_vector.h>

RVector *r_create_vector(size_t size)
{
    RVector *vector = malloc(sizeof(RVector));

    vector->size = size;
    vector->data = malloc(sizeof(float) * vector->size);

    return vector;
}

void r_free_vector(RNONNULL RVector *vector)
{
    free(vector->data);
    vector->size = 0;
    free(vector);
}

RVector *r_mat_vec_mul(const RNONNULL RMatrix *matrix, const RNONNULL RVector *vector)
{
    if (matrix->cols != vector->size)
    {
        printf("[ERROR]: The number of columns in the matrix should be the same as the vector size\n");
        return NULL;
    }

    RVector *result = malloc(sizeof(RVector));

    for (size_t i = 0; i < matrix->rows; i++)
    {
        float sum = 0.0f;
        for (size_t j = 0; j < matrix->cols; j++)
        {
            sum += matrix->data[RMatrixIDX(i, j, matrix->cols)] * vector->data[j];
        }
        result->data[i] = sum;
    }

    return result;
}

void r_print_vector(RNONNULL RVector *v, const RNONNULL char *name)
{
    printf("%s = [", name);
    for (int i = 0; i < v->size; i++)
    {
        printf("%.2f", v->data[i]);
        if (i < v->size - 1)
            printf(", ");
    }
    printf("]\n");
}
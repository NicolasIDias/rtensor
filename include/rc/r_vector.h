#pragma once

#include <rc/r_types.h>
#include <rc/r_matrix.h>

typedef struct r_vector_t
{
    float *data;
    size_t size;
} RVector;

// VECTOR OPERATIONS
RVector *r_create_vector(size_t size);
void r_free_vector(RNONNULL RVector *vector);
void r_print_vector(RNONNULL RVector *v, const RNONNULL char *name);

// VEC AND MATRIX OPERATIONS
RVector *r_mat_vec_mul(const RNONNULL RMatrix *matrix, const RNONNULL RVector *vector);
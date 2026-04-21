#pragma once

#include <rc/r_types.h>
#include <rc/r_matrix.h>
#include <rc/r_vector.h>

typedef struct r_layer_dense_t
{
    RMatrix *weights;
    RVector *biases;
} RLayerDense;

#pragma once

#include <rc/r_types.h>
#include <rc/r_matrix.h>
#include <rc/r_vector.h>

typedef struct r_layer_dense_t
{
    RMatrix *weights;
    RVector *biases;
} RLayerDense;

RLayerDense *r_create_layer(size_t n_inputs, size_t n_neurons);
RMatrix *r_layer_forward(const RNONNULL RLayerDense *layer, const RNONNULL RMatrix *inputs);
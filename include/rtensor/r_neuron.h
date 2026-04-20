#pragma once

#include <rtensor/r_types.h>

typedef struct r_neuron_t
{
    size_t n_inputs;
    float *weights;
    float bias;
} RNeuron;
#pragma once

#include "../internals.h"

typedef struct r_neuron_t
{
    size_t n_inputs;
    float *weights;
    float bias;
} RNeuron;
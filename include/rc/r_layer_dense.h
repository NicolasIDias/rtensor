#pragma once

#include <rc/r_types.h>

typedef struct r_neuron_t
{
    size_t n_inputs;
    float *weights;
    float bias;
} RNeuron;

float r_calc_neuron_output(const RNONNULL RNeuron *neuron, const RNONNULL float *inputs, size_t input_count);

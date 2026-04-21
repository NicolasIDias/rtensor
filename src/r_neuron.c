#include <rc/r_layer_dense.h>
#include <rc/r_types.h>

float r_calc_neuron_output(const RNONNULL RNeuron *neuron, const RNONNULL float *inputs, size_t input_count)
{
    if (neuron->n_inputs != input_count)
    {
        printf("[ERROR]: Neuron->weights and inputs should be the same size\n");
        exit(1);
    }

    float result = 0.0f;
    for (size_t i = 0; i < neuron->n_inputs; i++)
    {
        result += neuron->weights[i] * inputs[i];
    }
    result += neuron->bias;
    return result;
}


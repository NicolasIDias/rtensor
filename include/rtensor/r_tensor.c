#pragma once

#include "../internals.h"

typedef struct r_tensor_t
{
    float *data;
    size_t rows;
    size_t cols;
    size_t stride;
} RTensor;
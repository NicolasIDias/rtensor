#pragma once

#include <rtensor/r_types.h>

#define RTensorIDX(tensor, row, col) ((col) * (tensor)->stride + (row))

typedef struct r_tensor_t
{
    float *data;
    size_t rows;
    size_t cols;
    size_t stride;
} RTensor;

// TensorA and TensorB should be the same size ()
float r_tensor_dot(RNONNULL RTensor *tensorA, RNONNULL RTensor *tensorB);

void rtensor_matmul(RTensor *originA, RTensor *originB, RTensor *dest);
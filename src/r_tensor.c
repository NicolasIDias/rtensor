#include <rtensor/r_tensor.h>
#include <rtensor/r_types.h>

float r_tensor_dot(RNONNULL RTensor *tensorA, RNONNULL RTensor *tensorB)
{
    if (tensorA->cols != tensorB->cols || tensorA->rows != tensorB->rows)
    {
        printf("[ERROR]: TensorA and TensorB should be the same size");
        exit(1);
    }
    float result = 0.0f;
    size_t total = tensorA->rows * tensorA->cols;
    for (size_t i = 0; i < total; i++)
    {
        result += tensorA->data[i] * tensorB->data[i];
    }
    return result;
}
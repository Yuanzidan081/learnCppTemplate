#include "stdint.h"
template <typename T>
void copy(T* dst, T* src, size_t elemCount)
{
    for (size_t i = 0; i < elemCount; ++i) {
        dst[i] = src[i];
    }
}
#include "func1.hpp"

int main()
{
    X<float *, int>::ToString();
    X<double *, int>::ToString();
    X<double, double>::ToString();
    X<float *, double *>::ToString();
    // X<float *, float *>::ToString();
    X<double, float *>::ToString();
    X<int, double *>::ToString();
    // X<int *, int>::ToString();
    X<double*, double>::ToString();
    return 0;
}
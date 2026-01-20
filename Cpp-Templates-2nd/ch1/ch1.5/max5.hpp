#include <iostream>

template <typename T>
T max5(T a, T b)
{
    std::cout << "Called template max5(T, T)" << std::endl;
    return (a > b) ? a : b;
}

template <typename T>
T max5(T a, T b, T c)
{
    std::cout << "Called template max5(T, T, T)" << std::endl;
    return max5(max5(a, b), c);
}

int max5(int a, int b)
{
    std::cout << "Called non-template max5(int, int)" << std::endl;
    return (a > b) ? a : b;
}
#include <string>
#include <cstring>
#include <iostream>

template <typename T>
T max3(T a, T b)
{
    std::cout << "Called template max3(T, T)" << std::endl;
    return (a > b) ? a : b;
}

template <typename T>
T* max3(T* a, T* b)
{
    std::cout << "Called template max3(T*, T*)" << std::endl;
    return *b < *a ? a : b;
}

char const* max3(char const* a, char const* b)
{
    std::cout << "Called non-template max3(const char*, const char*)" << std::endl;
    return std::strcmp(a, b) > 0 ? a : b;
}

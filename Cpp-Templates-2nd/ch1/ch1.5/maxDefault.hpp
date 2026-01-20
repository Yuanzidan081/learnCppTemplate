#include <iostream>
int max(int a, int b)
{
    std::cout << "Called max(int, int)" << std::endl;
    return (a > b) ? a : b;
}

template <typename T>
T max(T a, T b)
{
    std::cout << "Called template max(T, T)" << std::endl;
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
auto max2(T1 a, T2 b)
{
    std::cout << "Called template max(T1, T2)" << std::endl;
    return (a > b) ? a : b;
}

template <typename RT, typename T1, typename T2>
RT max2(T1 a, T2 b)
{
    std::cout << "Called template max(RT, T1, T2)" << std::endl;
    return (a > b) ? a : b;
}   
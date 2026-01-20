#include <cstring>
#include <iostream>
template <typename T>
T const& max4(T const& a, T const& b)
{
    std::cout << "Called template max4(T const&, T const&)" << std::endl;
    return (a > b) ? a : b;
}

char const* max4(char const* a, char const* b)
{
    std::cout << "Called non-template max4(const char* const&, const char* const&)" << std::endl;
    return std::strcmp(a, b) > 0 ? a : b;
}

template <typename T>
T const& max4(T const& a, T const& b, T const& c)
{
    std::cout << "Called template max4(T const&, T const&, T const&)" << std::endl;
    return max4(max4(a, b), c);
}
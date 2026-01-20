#include "maxConstExpr.hpp"
#include <iostream>
#include <array>
int main()
{
    {
        auto x = ::max(sizeof(char), 1000u);
        std::cout << "max(sizeof(char), 1000u) = " << x << std::endl;

        int a[::max(sizeof(char), 1000u)];
        std::array<std::string, ::max(sizeof(char), 1000u)> arr;
    }

    return 0;
}
#include <iostream>
#include "func1.hpp"
#include "func2.hpp"
#include "func3.hpp"
#include "func4.hpp"
int main()
{
    {
        struct Y<int> y;
        y.foo();
    }

    {
        struct X2<int> x2;
        x2.v = 42;
        struct A2 a2;
        x2.convertTo(a2);
        std::cout << "A2.v = " << a2.v << std::endl;
    }

    {
        struct X3<float> x3;
        x3.v = 84;
        struct A3 a3;
        x3.convertTo(a3);
        std::cout << "A3.v = " << a3.v << std::endl;
    }
    return 0;
}
#include <iostream>
#include "func1.hpp"

int main()
{
    // func1.hpp test
    {
        int a = 10;
        double b = 20.5;
        auto result = max(a, b); // Should deduce RT to double
        std::cout << "Max of " << a << " and " << b << " is " << result << std::endl;

        float c = 15.5f;
        long d = 12L;
        auto result2 = max2(c, d); // Should deduce RT to common type, can't be reference
        std::cout << "Max2 of " << c << " and " << d << " is " << result2 << std::endl;

        int i = 4;
        long l = 1000;
        auto result3 = max3(i, l); // RT defaults to long
        auto result4 = max3<double>(i, l); // RT explicitly set to double
        std::cout << "Max3 of " << i << " and " << l << " is " << result3 << std::endl;
        std::cout << "Max3 with double of " << i << " and " << l << " is " << result4 << std::endl;
    }
}
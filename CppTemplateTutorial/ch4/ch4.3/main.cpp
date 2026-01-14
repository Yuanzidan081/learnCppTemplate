#include "func1.hpp"
#include <iostream>
int main()
{
    {
        print_float(3.14f);
        // print_float(42); // This line would cause a compilation error
        int x = 10;
        inc_counter<int>(x);
        std::cout << "Incremented value: " << x << std::endl;
        int y = 100;
        inc_counter2<int>(y);
        std::cout << "Incremented value using inc_counter2: " << y << std::endl;
    }
    return 0;
}
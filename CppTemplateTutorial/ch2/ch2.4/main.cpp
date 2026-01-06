#include <iostream>
#include "array.hpp"
#include "foo.hpp"

int main()
{
    {
        array<int, 5> intArray;
        for (int i = 0; i < 5; ++i)
            intArray.data[i] = i * 10;
        for (int i = 0; i < 5; ++i)
            std::cout << intArray.data[i] << " ";
        std::cout << std::endl;
    }

    {
        foo();
        foo2();
    }

    return 0;
}
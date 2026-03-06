#include <iostream>
#include "lessarray.hpp"
#include "lessstring.hpp"
#include "arrays.hpp"
int a2[]{0, 8, 15};
int main()
{
    // lessarray Test
    {
        int x[] = {1, 2, 3};
        int y[] = {1, 2, 3, 4, 5};
        std::cout << less_array(x, y) << std::endl;
        std::cout << less_array("ab", "abc") << std::endl;        
    }

    // lessstring Test
    {
        std::cout << less_string("abc", "abd") << std::endl;
        std::cout << less_string("abd", "abc") << std::endl;
        std::cout << less_string("abc", "abc") << std::endl;
    }

    // arrays Test
    {
        int a1[42];
        MyClass<decltype(a1)>::print(); // use MyClass<T[SZ]>
        extern int a2[];
        MyClass<decltype(a2)>::print(); // use MyClass<T[]>
        foo(a1, a1, a1, a2, a2, a2, a2);
    }
    return 0;
}


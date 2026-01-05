#include <iostream>

template <typename T>
class A{};

template <typename T>
T foo(A<T> a)
{
    std::cout << "foo called" << std::endl;
    return T{};
}
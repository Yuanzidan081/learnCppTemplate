#include <iostream>
struct X
{
    typedef int type;
};

struct Y
{
    typedef int type2;
};

template <typename T>
void foo(typename T::type x)
{
    std::cout << "foo with type T::type called" << std::endl;
}

template <typename T>
void foo(typename T::type2 x)
{
    std::cout << "foo with type T::type2 called" << std::endl;
}

template <typename T>
void foo(T x)
{
    std::cout << "foo with type T called" << std::endl;
}
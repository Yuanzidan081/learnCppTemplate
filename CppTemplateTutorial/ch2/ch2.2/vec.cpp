#include <iostream>
#include "vec.hpp"

template <typename T>
void vec<T>::clear()
{
    std::cout << "vec::clear() called" << std::endl;
}

template class vec<int>; // 显式实例化
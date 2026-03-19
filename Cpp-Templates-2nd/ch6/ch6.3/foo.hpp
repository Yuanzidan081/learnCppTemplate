#include <type_traits>
#include <iostream>
template <typename T>
typename std::enable_if<(sizeof(T) > 4)>::type
foo()
{
    std::cout << "called foo" << std::endl;
}

template <typename T>
typename std::enable_if_t<(sizeof(T) <= 4)>
foo2()
{
    std::cout << "called foo2" << std::endl;
}

template <typename T>
std::enable_if_t<(sizeof(T) > 4), T>
foo3()
{
    std::cout << "called foo3" << std::endl;
    return T();
}

template <typename T,
typename = std::enable_if_t<(sizeof(T) > 4)>>
T foo4()
{
    std::cout << "called foo4" << std::endl;
    return T();
}

template <typename T>
using EnableIfSizeGreater4 = std::enable_if_t<(sizeof(T) > 4)>;

template <typename T,
typename = EnableIfSizeGreater4<T>>
T foo5()
{
    std::cout << "called foo5" << std::endl;
    return T();
}

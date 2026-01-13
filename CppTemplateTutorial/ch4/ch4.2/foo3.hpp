#include <iostream>
template <typename ArgT> void foo3(ArgT&& a)
{
    std::cout << "foo3 called" << std::endl;
}
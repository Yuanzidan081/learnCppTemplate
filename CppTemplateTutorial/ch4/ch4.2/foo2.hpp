#include <type_traits>
#include <iostream>
template <typename ArgT>
void foo2(
    ArgT&& a, 
    typename std::enable_if<
        std::is_same<std::decay_t<ArgT>, float>::value
    >::type* = nullptr
)
{
    std::cout << "foo2 with float called" << std::endl;
}

void foo2_2(float&& a)
{
    std::cout << "foo2 with float rvalue called" << std::endl;
}
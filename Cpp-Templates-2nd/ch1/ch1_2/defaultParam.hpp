#include <iostream>
#include <string>
template <typename T>
void f1(T = "")
{
    std::cout << "f1 called" << std::endl;
}

template <typename T = std::string>
void f2(T = "")
{
    std::cout << "f2 called" << std::endl;
}
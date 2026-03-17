#include <utility>
#include <iostream>

class X {

};

void g(X&)
{
    std::cout << "g(X&)\n";   
}

void g(const X&)
{
    std::cout << "g(const X&)\n";   
}

void g(X&&)
{
    std::cout << "g(X&&)\n";   
}

template <typename T>
void f(T&& val)
{
    g(std::forward<T>(val));
}

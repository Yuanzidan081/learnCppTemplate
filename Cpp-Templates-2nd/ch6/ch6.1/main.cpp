#include "move2.hpp"

int main()
{
    X v;
    X const c;
    f(v); // g(X&)
    f(c); // g(const X&)
    f(X()); // g(X&&)
    f(std::move(v)); // g(X&&) - std::move()将v转换为右值引用，允许g(X&&)被调用
}

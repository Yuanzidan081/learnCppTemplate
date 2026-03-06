#include <iostream>
template <typename T>
class Base
{
public:
    void bar() { std::cout << "Base::bar()\n"; }
};

template <typename T>
class Derived: public Base<T>
{
public:
    void foo()
    {
        // bar(); // error: 'bar' was not declared in this scope
        this->bar(); // OK: Base::bar()
        Base<T>::bar(); // OK: Base::bar()
    }
};
int main()
{
    Derived<int> d;
    d.foo();
    return 0;
}

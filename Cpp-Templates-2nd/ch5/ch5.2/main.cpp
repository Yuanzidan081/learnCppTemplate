#include <iostream>
template <typename T>
void foo()
{
    T x{};
    std::cout << "foo(): " << x << std::endl;
}

template <typename T>
void foo2(T p = T{})
{
    std::cout << "foo2(): " << p << std::endl;
}


template <typename T>
class MyClass
{
private:
    T x;
public:
    MyClass(): x{} {
        std::cout << "MyClass(): " << x << std::endl;
    }
};

int main()
{
    foo<int>();
    foo2<int>();
    MyClass<int> myclass;
    return 0;
}

#include "stdint.h"
#include <iostream>
/// section1 ///
template <int i> 
class A
{ };

void foo();
void foo()
{
    int x = 3;
    A<5> a; // 正确
    // A<x> a2; // 错误，模板参数必须是编译期常量
}

/// section2 ///
template <int i> 
class A2
{
public:
    void foo(int x)
    {

    }
};
template <uint8_t a, typename b, void* c>
class B
{ };

template <bool, void(*a)()>
class C
{ };

template <void(A2<3>::*a)(int)> 
class D
{ };

template <int i> 
int add(int a)
{
    return a + i;
}


void foo2();
void foo2()
{
    A2<5> a;
    B<7, A<5>, nullptr> b;
    C<false, &foo2> c;
    D<&A2<3>::foo> d;
    int x = add<3>(5);
    std::cout << "the result of foo2() is " << x << std::endl;
}

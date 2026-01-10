#include <iostream>
template <typename T>
class RemovePointer
{
public:
    typedef T Type;
};

template <typename T>
class RemovePointer<T*>
{
public:
    // typedef T Type; // 去掉一层指针，但是无法去掉多层指针
    typedef typename RemovePointer<T>::Type Type; // 递归去掉多层指针
};

void foo()
{
    RemovePointer<int>::Type a = 10;      // a 是 int
    RemovePointer<int*>::Type b = 20;     // b 是 int
    RemovePointer<int**>::Type c = 30;    // c 是 int
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
}
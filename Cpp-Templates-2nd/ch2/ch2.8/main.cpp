#include "stack1.hpp"
#include "stackDefaultParam.hpp"
#include <vector>
#include <type_traits>
#include <iostream>
#include <string>
template <typename T>
using vectorIterator = typename std::vector<T>::iterator;

int main()
{
    // stack1.hpp test
    {
        typedef Stack<int> intStack;
        intStack intS;
        using doubleStack = Stack<double>;
        doubleStack doubleS;
    }
    // stackDefaultParam.hpp test
    {
        DequeStack<int> intDequeStack;
    }

    {
        vectorIterator<int> iter;
    }
    // add_const_t C++14
    {
        using T1 = int;
        using ConstT = std::add_const_t<T1>;
        std::cout << std::is_same_v<ConstT, const int> << std::endl;

        using T2 = const std::string;
        using ConstT2 = std::add_const_t<T2>; // 仍为 const string
        std::cout << std::is_same_v<ConstT2, const std::string> << std::endl; // 输出 true
        
        using T3 = int&;
        using ConstT3 = std::add_const_t<T3>; // 仍为 int&，而非 const int&
        std::cout << std::is_same_v<ConstT3, int&> << std::endl; // 输出 true

        using T4 = int*;
        using ConstT4 = std::add_const_t<T4>; // 等价于 int* const（指针本身 const）
        std::cout << std::is_same_v<ConstT4, int* const> << std::endl; // 输出 true
    }
    return 0;
}
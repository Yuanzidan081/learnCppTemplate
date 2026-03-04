#pragma once
#include "print.hpp"
template <typename... T>
void addOne(T const&... args)
{
    // print(arg + 1...);// Error: 编号的预期结尾后有多余文本
    print(args + 1 ...); // OK
    print((args + 1) ...); // OK
}
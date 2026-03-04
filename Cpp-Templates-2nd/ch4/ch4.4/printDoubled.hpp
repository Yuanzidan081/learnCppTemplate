#pragma once
#include "print.hpp"
template <typename... T>
void printDoubled(T const&... args)
{
    print(args + args...);
}
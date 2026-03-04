#pragma once    
#include <iostream>
void print()
{
    std::cout << std::endl;
}

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
    std::cout << firstArg << " ";
    print(args...);
}
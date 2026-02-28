#include <iostream>

template <typename T>
void print2(T arg)
{
    std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print2(T firstArg, Types... args)
{
    print2(firstArg);
    print2(args...);
}
#include <iostream>

// 递归终止版本：无参函数，什么都不做
void print3() {}

template <typename T, typename... Types>
void print3(T firstArg, Types... args)
{
    std::cout << " sizeof...(Types): " << sizeof...(Types) << " sizeof...(args): " << sizeof...(args) << std::endl;
    std::cout << firstArg << std::endl;
    print3(args...);
}
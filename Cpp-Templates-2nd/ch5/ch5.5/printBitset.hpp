#include <iostream>
#include <bitset>
template <size_t N>
void printBitSet(std::bitset<N> const& bs)
{
    // .template 是一个语法标记，强制编译器将后面的标识符（这里是 to_string）当作模板成员函数处理，明确告诉编译器：“接下来的 < 是模板参数的开始，不是小于号”。
    std::cout << bs.template to_string<char, std::char_traits<char>, std::allocator<char> >() << std::endl;
}
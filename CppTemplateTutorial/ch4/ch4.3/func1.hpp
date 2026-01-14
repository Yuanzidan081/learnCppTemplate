#include <concepts>
#include <type_traits>
#include <iostream>
// remove_cvref_t先把 ArgT 的引用、const/volatile 都去掉，然后检查剩下的类型是不是 float。
template<typename ArgT>
requires std::same_as<std::remove_cvref_t<ArgT>, float>
void print_float(ArgT value) {
    std::cout << "Float value: " << value << std::endl;
}

// 我们对T的要求是得有++
template <typename T>
concept Incrementable = requires (T t) { ++t; };

template <Incrementable T>
void inc_counter(T& intTypeCounter) {
    ++intTypeCounter;
}

template <typename T> requires (requires (T t) { ++t; })
void inc_counter2(T& cnt)
{
    ++cnt;
}
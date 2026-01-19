#include <type_traits>
template <typename T1, typename T2, typename RT>
RT max(T1 a, T2 b) {
    return (a > b) ? a : b;
}

template <typename RT, typename T1, typename T2>
RT max2(T1 a, T2 b)
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
auto max3(T1 a, T2 b)
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
auto max4(T1 a, T2 b) -> decltype(a > b ? a : b)
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
auto max5(T1 a, T2 b) -> decltype(true ? a : b) // 说明只是一个声明，让编译器使用三元操作符
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
auto max6(T1 a, T2 b) -> typename std::decay<decltype(true ? a : b)>::type // decay去除引用和cv限定符
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
std::common_type_t<T1, T2> max7(T1 a, T2 b)
{
    return (a > b) ? a : b;
}
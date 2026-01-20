#include <type_traits>

template <typename T1, typename T2,
typename RT = std::decay_t<decltype(true ? T1() : T2())>>
RT max(T1 a, T2 b) {
    return (a > b) ? a : b;
}

template <typename T1, typename T2,
typename RT = std::common_type_t<T1, T2>>
RT max2(T1 a, T2 b) {
    return (a > b) ? a : b;
}

template <typename RT = long, typename T1, typename T2>
RT max3(T1 a, T2 b) {
    return (a > b) ? a : b;
}
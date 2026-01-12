#include <type_traits>

template <typename T> T CustomDiv2(T lhs, T rhs) {
    T v{};
    return v;
}

template <typename T, 
        bool IsFloat = std::is_floating_point<T>::value, 
        bool IsIntegral = std::is_integral<T>::value>
struct SafeDivide2 {
    static T Do(T lhs, T rhs)
    {
        return CustomDiv2(lhs, rhs);
    }
};

template <typename T> struct SafeDivide2<T, true, false> {
    static T Do(T lhs, T rhs)
    {
        return lhs / rhs;
    }
};

template <typename T> struct SafeDivide2<T, false, true> {
    static T Do(T lhs, T rhs)
    {
        return rhs == 0 ? 0 : lhs / rhs;
    }
};


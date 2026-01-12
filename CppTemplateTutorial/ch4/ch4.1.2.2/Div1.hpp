#include <type_traits>

template <typename T> T CustomDiv(T lhs, T rhs) {
    T v{};
    return v;
}

template <typename T, bool IsFloat = std::is_floating_point<T>::value> struct SafeDivide {
    static T Do(T lhs, T rhs)
    {
        return CustomDiv(lhs, rhs);
    }
};

template <typename T> struct SafeDivide<T, true> {
    static T Do(T lhs, T rhs)
    {
        return lhs / rhs;
    }
};

template <typename T> struct SafeDivide<T, false> {
    static T Do(T lhs, T rhs)
    {
        return lhs;
    }
};

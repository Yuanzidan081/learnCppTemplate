#include <type_traits>

template <typename T> T CustomDiv3(T lhs, T rhs) {
    T v{};
    return v;
}

template <typename T, 
        typename Enabled = std::true_type> 
struct SafeDivide3 {
    static T Do(T lhs, T rhs)
    {
        return CustomDiv3(lhs, rhs);
    }
};

template <typename T> 
struct SafeDivide3<T, 
                typename std::is_floating_point<T>::type> 
{
    static T Do(T lhs, T rhs)
    {
        return lhs / rhs;
    }
};

template <typename T> 
struct SafeDivide3<T, 
                typename std::is_integral<T>::type> 
{
    static T Do(T lhs, T rhs)
    {
        return rhs == 0 ? 0 : lhs / rhs;
    }
};
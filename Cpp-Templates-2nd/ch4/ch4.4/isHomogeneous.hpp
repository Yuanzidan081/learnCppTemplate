#pragma once
#include <type_traits>
template <typename T1, typename... TN>
constexpr bool isHomogeneous(T1, TN...)
{
    return (std::is_same<T1, TN>::value && ...);
}

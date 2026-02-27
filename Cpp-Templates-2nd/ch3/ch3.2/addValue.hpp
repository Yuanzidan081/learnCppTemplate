template <int Val, typename T>
T addValue(T value)
{
    return value + Val;
}

template <auto Val, typename T = decltype(Val)>
T addValue2(T value)
{
    return value + Val;
}

template <typename T, T Val = T{}>
T addValue3(T value)
{
    return value + Val;
}
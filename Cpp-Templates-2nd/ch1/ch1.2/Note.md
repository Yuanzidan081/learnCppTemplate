# 类型推导时的类型转换
1. 引用声明参数，不用简单的转换。
```cpp
template <typename T>
T max(T const& a, T const& b)
{
    return b < a ? a : b;
}
```
2. 值声明参数，做简单的转换：忽略const或volatile限定符，引用转换为引用类型，原始数组或函数转换为相应指针类型，对于相同模板参数T声明的两个参数，转换类型必须匹配。
```cpp
template <typename T>
T max(T a, T b)
{
    return b < a ? a : b;
}
```

# 默认参数类型推导
1. 类型推导不适用于默认调用参数
```cpp
template <typename T>
void f1(T = "")
{
    std::cout << "f1 called" << std::endl;
}
...
f1();  // Error，T cannot be deduced
```

为了支持，为模板参数声明一个默认实参即可：
```cpp
template <typename T = std::string>
void f2(T = "")
{
    std::cout << "f2 called" << std::endl;
}
...
f2(); // OK!
```
能不能直接写成以下形式，不是更简单吗？

```cpp
template <typename T> requires (T t) { ++t; }
void inc_counter(T& cnt);
```

答案是：不能。 因为`requires`作为关键字/保留字是存在二义性的。当它用于函数模板或者类模板的声明时，它是一个`constraint`，后面需要跟着`concept`表达式；而用于`concept`中，则是一个`required expression`，用于`concept`的求解。既然`constraint`后面跟着一个`concept`表达式，而`requires`也可以用来定义一个`concept expression`，那么一个风骚的想法形成了：我能不能用 `requires (requires (T t) {++t;}) `来约束模板参数呢？

当然是可以的！C++就是这么的简（有）单（病）！

```cpp
template <typename T> requires (requires (T t) { ++t; })
void inc_counter(T& cnt);
```
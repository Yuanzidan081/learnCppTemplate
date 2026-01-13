#  `counter.hpp`里的实现的解释

首先，替换（substitution）只有在推断函数类型的时候，才会起作用。推断函数类型需要参数的类型，所以， `typename std::enable_if<std::is_integral<T>::value>::type` 这么一长串代码，就是为了让 enable_if 参与到函数类型中；

其次， `is_integral<T>::value` 返回一个布尔类型的编译器常数，告诉我们它是或者不是一个 `integral type，enable_if<C>` 的作用就是，如果这个 C 值为 True，那么 `enable_if<C>::type` 就会被推断成一个 `void` 或者是别的什么类型，让整个函数匹配后的类型变成 `void inc_counter<int>(int & counterInt, void* dummy = nullptr);` 如果这个值为 `False` ，那么 `enable_if<false>` 这个特化形式中，压根就没有这个 `::type`，于是替换就失败了。和我们之前的例子中一样，这个函数原型就不会被产生出来。

但这里写成：

```cpp
void inc_counter(ICounter& counterObj);
```

也是可以解决问题的，不需要复杂的编译器机制。当你觉得需要写 enable_if 的时候，首先要考虑到以下可能的替代方案：

+ 重载（适用于函数模板）
+ 偏特化（适用于类模板）
+ 虚函数

# `counter3.hpp`里的实现的解释

ICounter 不是已经空了吗，为什么我们还要用它作为基类呢？

```cpp
struct ICounter3 {};
struct Counter3 : public ICounter3 {
    void increase() {
        // Implementation of increase
        std::cout << "Counter3 increased" << std::endl;
    }
};

template <typename T> 
void inc_counter3(
    T& counterObj, 
    typename std::enable_if<std::is_base_of<ICounter3, T>::value>::type* = nullptr
    ) 
{ 
    counterObj.increase();
};
```

在本例中，我们用它来区分一个`counter`是不是继承自`ICounter`。最终目的，是希望知道 `counter` 有没有 `increase` 这个函数。在C++11之前，我们并没有办法去写类似于：

```cpp
template <typename T> void foo(T& c, decltype(c.increase())* = nullptr);
```

因为假如 `T` 是 `int`，那么 `c.increase()` 这个函数调用就不存在。但它又不属于`Type Failure`，而是一个`Expression Failure`，在C++11之前它会直接导致编译器出错，这并不是我们所期望的。所以我们才退而求其次，用一个类似于标签的形式来提供我们所需要的类型信息。这种和类型有关的信息我们可以称之为 `type traits`。

# `counter4.hpp`里的实现的解释

到了C++11，它正式提供了 `Expression SFINAE`，这时我们就能抛开 `ICounter` 这个无用的Tag，直接写出我们要写的东西：

```cpp
struct Counter {
    void increase() {
        // Implements
    }
};

template <typename T>
void inc_counter(T& intTypeCounter, std::decay_t<decltype(++intTypeCounter)>* = nullptr) {
    ++intTypeCounter;
}

template <typename T>
void inc_counter(T& counterObj, std::decay_t<decltype(counterObj.increase())>* = nullptr) {
    counterObj.increase();
}

void doSomething() {
    Counter cntObj;
    uint32_t cntUI32;

    // blah blah blah
    inc_counter(cntObj);
    inc_counter(cntUI32);
}
```

# 其他情况

还有一种情况只能使用 `SFINAE`，而无法使用包括继承、重载在内的任何方法，这就是`Universal Reference`。

```cpp
// 这里的a是个通用引用，可以准确的处理左右值引用的问题。
template <typename ArgT> void foo(ArgT&& a);
```

假如我们要限定ArgT只能是 float 的衍生类型，那么写成下面这个样子是不对的，它实际上只能接受 float 的右值引用。

```cpp
void foo(float&& a);
```

此时的唯一选择，就是使用Universal Reference，并增加 enable_if 限定类型，如下面这样：

```cpp
template <typename ArgT>
void foo(
    ArgT&& a, 
    typename std::enable_if<
        std::is_same<std::decay_t<ArgT>, float>::value
    >::type* = nullptr
);
```

从上面这些例子可以看到，`SFINAE`最主要的作用，是保证编译器在泛型函数、偏特化、及一般重载函数中遴选函数原型的候选列表时不被打断。除此之外，它还有一个很重要的元编程作用就是实现部分的编译期自省和反射。

虽然它写起来并不直观，但是对于既没有编译器自省、也没有`Concept`的C++11来说，已经是最好的选择了。
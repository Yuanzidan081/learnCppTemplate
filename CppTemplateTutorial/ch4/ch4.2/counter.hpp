#include <type_traits>
#include <iostream>
struct ICounter {
    virtual void increase() = 0;
    virtual ~ICounter() = default;
};

struct Counter : public ICounter
{
    void increase() override {
        // Implementation of increase
        std::cout << "Counter increased" << std::endl;
    }
};

// 下面两个其实是一样的签名
/*
template <typename T>
void inc_counter(T& counterObj)
{
    counterObj.increase();
}

template <typename T>
void inc_counter(T& intTypeCounter)
{
    ++intTypeCounter;
}
*/

template <typename T>
void inc_counter(T& counterObjm,
    typename std::enable_if<std::is_base_of<ICounter, T>::value>::type* = nullptr)
{
    counterObjm.increase();
}

template <typename T>
void inc_counter(T& counterInt, 
    typename std::enable_if<std::is_integral<T>::value>::type* = nullptr)
{
    ++counterInt;
}   

void doSomething()
{
    Counter counterObj;
    inc_counter(counterObj); // Calls the first overload

    int intTypeCounter = 0;
    inc_counter(intTypeCounter); // Calls the second overload
}
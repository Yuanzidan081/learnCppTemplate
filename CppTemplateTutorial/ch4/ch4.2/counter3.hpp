#include <type_traits>
#include <utility>
#include <cstdint>
#include <iostream>

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

template <typename T>
void inc_counter3(
    T& counterInt, 
    typename std::enable_if<std::is_integral<T>::value>::type* = nullptr
    ) 
{ 
    ++counterInt; 
};

void doSomething3() {
    Counter3 counterObj;
    inc_counter3(counterObj); // Calls the first overload

    uint64_t intTypeCounter = 0;
    inc_counter3(intTypeCounter); // Calls the second overload
}


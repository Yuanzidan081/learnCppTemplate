// Expression SFINAE
#include <type_traits>
#include <iostream>
struct counter4
{
    void increase() {
        // Implementation of increase
        std::cout << "counter4 increased" << std::endl;
    }   
};


template <typename T>
void inc_counter4(
    T& counterObj,
    std::decay_t<decltype(counterObj.increase())>* = nullptr
    )
{
    counterObj.increase();
}

template <typename T>
void inc_counter4(
    T& counterInt,
    std::decay_t<decltype(++counterInt)>* = nullptr
    )
{
    ++counterInt;
}

void doSomething4() {
    counter4 counterObj;
    inc_counter4(counterObj); // Calls the first overload

    int intTypeCounter = 0;
    inc_counter4(intTypeCounter); // Calls the second overload
}
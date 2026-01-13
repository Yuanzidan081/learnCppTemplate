#include <iostream>
#include "stdint.h"
struct ICounter2 {};

struct Counter2: public ICounter2 {
    void increase() {
        // Implementation of increase
        std::cout << "Counter2 increased" << std::endl;
    }
};

template <typename T>
void inc_counter2(ICounter2& c) {};

template <typename T>
void inc_counter2(T& c) { ++c; };

void doSomething2() {
    Counter2 cntObj;
    uint32_t cntUI32;

    // 1 调用inc_counter(T& c)：BOOM！
    // inc_counter2(cntObj); 
    // 2，调用inc_counter(T& c)：参数类型完全匹配 ICounter2&，但模板参数 T 无法推导（因为 T 没被使用），编译器会认为这个模板「无法实例化」（或者说匹配优先级低）。BOOM！
    // inc_counter2(static_cast<ICounter2&>(cntObj)); 
    inc_counter2(cntUI32); // 3
}
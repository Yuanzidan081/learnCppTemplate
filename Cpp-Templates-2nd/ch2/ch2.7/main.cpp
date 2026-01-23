#include "stackDefaultParam.hpp"
#include <iostream>
#include <deque>
int main()
{
    // stackDefaultParam.hpp test
    {
        StackDefaultParam<int> intStack;

        StackDefaultParam<double, std::deque<double>> doubleStack;

        intStack.push(7);
        std::cout << intStack.top() << std::endl;
        intStack.pop();
        doubleStack.push(3.14);
        std::cout << doubleStack.top() << std::endl;
        doubleStack.pop();
    }
    return 0;
}
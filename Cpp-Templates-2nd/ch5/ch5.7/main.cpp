#include "stack8decl.hpp"
#include "stack9.hpp"
#include <iostream>
#include <vector>
int main()
{
    // stack8decl test
    {
        Stack8<int> intStack;
        intStack.push(42);
        std::cout << "intStack.top() = " << intStack.top() << std::endl;

        Stack8<double> doubleStack;
        doubleStack.push(3.14);
        std::cout << "doubleStack.top() = " << doubleStack.top() << std::endl;
    }

    // stack9 test
    {
        Stack9<int> intStack;
        intStack.push(42);
        std::cout << "intStack.top() = " << intStack.top() << std::endl;

        Stack9<double> doubleStack;
        doubleStack.push(3.14);
        std::cout << "doubleStack.top() = " << doubleStack.top() << std::endl;

        doubleStack = intStack;
        doubleStack.push(2.718);
        std::cout << "doubleStack.top() = " << doubleStack.top() << std::endl;

        Stack9<double, std::vector> vectorStack;
        vectorStack.push(5.5);
        vectorStack.push(6.6);
        std::cout << "vectorStack.top() = " << vectorStack.top() << std::endl;
        vectorStack = doubleStack;
        std::cout << "vectorStack: ";
        while (!vectorStack.empty()) {
            std::cout << vectorStack.top() << " ";
            vectorStack.pop();
        }
        std::cout << std::endl;
    }

}
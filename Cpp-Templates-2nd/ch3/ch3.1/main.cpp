#include "stacknontype.hpp"
#include <string>
#include <iostream>

int main()
{
    {
        Stack<int, 20> int20Stack;
        Stack<int, 40> int40Stack;
        Stack<std::string, 40> stringStack;
        int20Stack.push(7);
        std::cout << int20Stack.top() << std::endl;
        int20Stack.pop();
        stringStack.push("hello");
        std::cout << stringStack.top() << std::endl;
        stringStack.pop();
    }
    return 0;
}
#include <string>
#include "stack1.hpp"
int main()
{
    // stack1.hpp test
    {
        Stack<int> intStack;  // stack of ints
        Stack<std::string> stringStack; // stack of strings

        // manipulate int stack
        intStack.push(7);
        intStack.push(13);
        assert(intStack.top() == 13);
        intStack.pop();
        assert(intStack.top() == 7);
        intStack.pop();
        assert(intStack.empty());

        // manipulate string stack
        stringStack.push("hello");
        stringStack.push("world");
        assert(stringStack.top() == "world");
        stringStack.pop();
        assert(stringStack.top() == "hello");
        stringStack.pop();
        assert(stringStack.empty());
    }
}
#include <iostream>
#include <string>
#include "stackauto.hpp"
#include "message.hpp"

constexpr int i = 42; // 编译时期变量
CAuto<(i)> c;
int main()
{
    // Stack Test
    {
        Stack<int, 20u> int20Stack;
        Stack<std::string, 40> stringStack;
    
        int20Stack.push(42);
        std::cout << int20Stack.top() << std::endl;
        auto size1 = int20Stack.size();
    
        stringStack.push("Hello, World!");
        std::cout << stringStack.top() << std::endl;
        auto size2 = stringStack.size();
        // different types of size1 and size2!
        if (!std::is_same_v<decltype(size1), decltype(size2)>) {
            std::cout << "size1 and size2 have different types!" << std::endl;
        }
    
        // Stack<int, 3.14> piStack; // error: non-type template argument is not an integer constant expression
    }

    // Message Test
    {
        Message<42> intMessage;
        intMessage.print();

        static char const s[] = "Hello, World!";
        Message<s> stringMessage;
        stringMessage.print();
    }
    // CAuto Test
    {
        
        c.print();
    }

    return 0;
}


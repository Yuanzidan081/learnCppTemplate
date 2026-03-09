#include <vector>
#include <iostream>
#include "stack5decl.hpp"
#include "stack6assign.hpp"
#include "stack7decl.hpp"
#include "boolstringgetbool.hpp"
#include "printBitset.hpp"
#include "SomCompilerSpecificName.hpp"
int main()
{
    // stack5decl.hpp Test OK 
    {
        Stack<int> intStack;
        Stack<double> doubleStack;
        intStack.push(7);
        doubleStack.push(3.14);
        doubleStack = intStack;
    }

    // stack6assign.hpp Test OK 
    {
        Stack2<int> intStack;
        Stack2<double> doubleStack;
        intStack.push(7);
        doubleStack.push(3.14);
        doubleStack = intStack;
    }

    // stack7decl.hpp Test OK 
    {
        Stack3<int, std::vector<int>> intStack;
        intStack.push(7);
        intStack.push(8);
        std::cout << intStack.top() << std::endl; // 8
    }

    // boolstringgetbool.hpp Test OK 
    {
        std::cout << std::boolalpha;
        BoolString bs1("true");
        BoolString bs2("hello");
        std::cout << bs1.get() << std::endl;
        std::cout << bs1.get<bool>() << std::endl; // true
        std::cout << bs2.get() << std::endl;
        std::cout << bs2.get<bool>() << std::endl; // false
    }

    // printBitset.hpp Test OK 
    {
        std::bitset<8> bs(42);
        printBitSet(bs); // 00101010
    }
    
    // SomCompilerSpecificName Test OK 
    {
        SomeCompilerSpecificName func;
        std::cout << func(3, 4) << std::endl; // 7
        std::cout << func(3.5, 4) << std::endl; // 7.5
        std::cout << func(std::string("Hello, "), "world!") << std::endl; // Hello, world!
    }


    return 0;
}

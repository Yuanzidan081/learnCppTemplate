#include "stack3.hpp"

int main()
{
    // stack3.hpp test
    {
        Stack<std::string> ss;
        ss.push("Hello");
        ss.push("World");
        std::cout << ss << std::endl;
    }
    return 0;
}
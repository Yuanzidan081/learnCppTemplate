#include "stackSpec.hpp"

int main()
{
    // stackSpec.hpp test
    {
        Stack<std::string> ss;
        ss.push("Hello");
        ss.push("World");
        std::cout << ss << std::endl;
    }
    return 0;
}
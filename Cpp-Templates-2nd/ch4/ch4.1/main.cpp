#include "varprint1.hpp"
#include "varprint2.hpp"
#include "varprint3.hpp"
#include <string>
int main()
{
    // print Test
    {
        std::string s("world");
        print(7.5, "hello", s);
    }

    // print2 Test
    {
        std::string s("world");
        print2(7.5, "hello", s);
    }
    // print3 sizeof... Test
    {
        std::string s("world");
        print3(7.5, "hello", s);
    }
    return 0;
}


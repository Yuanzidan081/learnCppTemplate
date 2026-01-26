#include "func.hpp"
#include <iostream>

ValueWithComment(char const*, char const*) 
-> ValueWithComment<std::string>;
int main()
{
    {
        ValueWithComment<int> vc;
        vc.value = 42;
        vc.comment = "initial value";
        std::cout << "Value: " << vc.value << ", Comment: " << vc.comment << '\n';
    }

    {
        ValueWithComment vc2 = {"Hello", "initial value"};
        std::cout << "Value: " << vc2.value << ", Comment: " << vc2.comment << '\n';
    }
    return 0;
}
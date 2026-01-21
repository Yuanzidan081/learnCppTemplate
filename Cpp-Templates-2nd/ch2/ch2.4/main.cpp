#include "stack2_1.hpp"
#include "stack2_2.hpp"
#include "stack2_3.hpp"
#include <string>
int main()
{
    // stack2_1.hpp test
    {
        Stack<int> vs;
        vs.push(10);
        vs.push(20);
        std::cout << vs << std::endl;
    }
    // stack2_2.hpp test
    {
        Stack2<double> ds;
        ds.push(3.14);
        ds.push(2.71);
        std::cout << ds << std::endl;
    }
    // stack2_3.hpp test
    {
        Stack3<std::string> ss;
        ss.push("Hello");
        ss.push("World");
        std::cout << ss << std::endl;
    }
    return 0;
}
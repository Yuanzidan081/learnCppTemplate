#include "stack1.hpp"
#include <iostream>
#include <utility>
int main()
{
    {
        Stack<std::pair<int, int>> ps;
        ps.push({1, 2});
        ps.push({3, 4});
        std::cout << "Top element: (" << ps.top().first << ", " << ps.top().second << ")" << std::endl;
        // ps.printOn(std::cout); // Error: no operator<< for std::pair
    }
}

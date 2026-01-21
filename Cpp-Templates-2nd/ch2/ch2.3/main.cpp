#include "stack1.hpp"
#include <iostream>
int main()
{
    {
        Stack<int> vs;
        vs.push(10);
        vs.push(20);
        vs.printOn(std::cout);
        
        Stack<std::pair<int, int>> ps;
        ps.push({1, 2});
        ps.push({3, 4});
        std::cout << "Top element: (" << ps.top().first << ", " << ps.top().second << ")" << std::endl;
        // ps.printOn(std::cout); // Error: no operator<< for std::pair
    }
    return 0;
}

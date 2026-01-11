#include "defaultArg.hpp"

int main()
{
    {
        std::cout << "Testing DoWork with default template argument:" << std::endl;
        DoWork<int>::ToString();
        DoWork<float>::ToString();
        DoWork<double>::ToString();
        DoWork<int, int>::ToString();
        return 0;
    }

    return 0;
}
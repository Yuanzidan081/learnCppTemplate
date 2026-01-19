#include <iostream>
#include <string>
#include "max1.hpp"
#include "defaultParam.hpp"

int main()
{
    {
        int i1 = 17;
        int const i2 = 42;
        int imax1 = max(i1, i2); // OK T is int
        std::cout << "imax1: " << imax1 << std::endl;
        int imax2 = max(i2, i2); // OK T is explicitly int
        std::cout << "imax2: " << imax2 << std::endl;
        int& ir = i1;
        int imax3 = max(i1, ir); // OK T is int
        std::cout << "imax3: " << imax3 << std::endl;
        int arr[4] = {0};
        int* pmax = max(&i1, arr); // OK T is int*
        std::cout << "&i1: " << (&i1) << ", arr: " << arr << ", max(&i1, arr): " << pmax << std::endl;

        double d1 = 3.14;
        // double x = max(d1, i1); // Error: T cannot be both double and int
        double dmax = max(d1, static_cast<double>(i1)); // OK T is double
        std::cout << "dmax: " << dmax << std::endl;
        double dmax2 = max<double>(d1, i1); // OK T is explicitly double
        std::cout << "dmax2: " << dmax2 << std::endl;
        std::string s;
        // max("hello", s); // const char* 和 std::string不匹配
    }

    {
        f1(1); // OK, T is int
        // f1();  // Error，T cannot be deduced
        f2();   // OK, T is std::string
    }
}
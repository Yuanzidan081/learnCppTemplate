#include <iostream>
#include <complex>
#include "Div1.hpp"
#include "Div2.hpp"
#include "Div3.hpp"

int main()
{
    // Div1.hpp test
    {
        float floatResult = SafeDivide<float>::Do(5.0f, 2.0f);
        int intResult = SafeDivide<int>::Do(5, 0);
        std::cout << "floatResult: " << floatResult << ", intResult: " << intResult << std::endl;
    }
    // Div2.hpp test
    {
        float floatResult2 = SafeDivide2<float>::Do(5.0f, 2.0f);
        int intResult2 = SafeDivide2<int>::Do(5, 0);
        std::complex<float> cplxResult2 = SafeDivide2<std::complex<float>>::Do({5.0f, 1.0f}, {2.0f, 0.5f});
        std::cout << "floatResult2: " << floatResult2 << ", intResult2: " << intResult2 << std::endl << "cplxResult2: " << cplxResult2 << std::endl;
    }
    // Div3.hpp test
    {
        float floatResult3 = SafeDivide3<float>::Do(5.0f, 2.0f);
        int intResult3 = SafeDivide3<int>::Do(5, 0);
        std::complex<float> cplxResult3 = SafeDivide3<std::complex<float>>::Do({5.0f, 1.0f}, {2.0f, 0.5f});
        std::cout << "floatResult3: " << floatResult3 << ", intResult3: " << intResult3 << std::endl << "cplxResult3: " << cplxResult3 << std::endl;
    }
    return 0;

}
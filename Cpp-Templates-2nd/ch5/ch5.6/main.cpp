#include <iostream>
#include <array>
#include <limits>
#include "unit1.hpp"
#include "MyClass.hpp"
template <typename T = long double>
constexpr T pi{3.1415926535897932385};


template <int N>
std::array<int, N> arr{};

template <auto N>
constexpr decltype(N) dval = N;

/*
namespace std {
    template <typename T> class numeric_limits
    {
    public:
        static constexpr bool is_signed = false;
    };
}
*/
template <typename T>
constexpr bool isSigned = std::numeric_limits<T>::is_signed;
int main()
{
    // pi Test
    {
        std::cout << pi<> << std::endl; // 3.14159
        std::cout << pi<double> << std::endl; // 3.14159
        std::cout << pi<float> << std::endl; // 3.14159
    }

    // unit1.hpp Test OK 
    {
        val<long> = 42;
        print(); // 42
    }

    // arr Test
    {
        std::cout << dval<'c'> << std::endl; // c
        arr<10>[0] = 42;
        for (std::size_t i = 0; i < arr<10>.size(); ++i)
        {
            std::cout << arr<10>[i] << ' '; // 42 0 0 0 0 0 0 0 0 0
        }
        std::cout << std::endl;
    }

    // MyClass.hpp Test OK 
    {
        std::cout << MyClass<int>::max << std::endl; // 1000
        std::cout << myMax<double> << std::endl; // 1000
    }

    // isSigned Test
    {
        std::cout << std::boolalpha;
        std::cout << isSigned<int> << std::endl; // true
        std::cout << isSigned<unsigned int> << std::endl; // false
    }

    {
        const int x = 42;
        int y = 23;
        std::cout << std::is_const_v<decltype(x)> << std::endl; // true
        std::cout << std::is_const_v<decltype(y)> << std::endl; // false
    }
}
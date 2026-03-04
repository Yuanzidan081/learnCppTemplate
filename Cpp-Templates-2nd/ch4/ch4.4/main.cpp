#include <iostream>
#include <vector>
#include <complex>
#include <string>
#include <tuple>
#include <variant>
#include <array>
#include "printDoubled.hpp"
#include "addOne.hpp"
#include "isHomogeneous.hpp"
#include "printElems.hpp"
#include "printIdx.hpp"
#include "printByIdx.hpp"
#include "varusing.hpp"
int main()
{
    // printDoubled.hpp Test
    {
        printDoubled(7.5, std::string("hello"), std::complex<double>(3.0, 4.0));
        // 15 hellohello (6,8) 
    }
    // addOne.hpp Test
    {
        addOne(2, 7.5, 100);
        // 3 8.5 101
        // 3 8.5 101
    }
    // isHomogeneous.hpp Test
    {
        std::cout << std::boolalpha;
        std::cout << isHomogeneous(1, 2, 3) << std::endl; // true
        std::cout << isHomogeneous(1, 2.0, 3) << std::endl; // false
        std::cout << isHomogeneous(std::string("a"), std::string("b")) << std::endl; // true
        std::cout << isHomogeneous(std::string("a"), "b") << std::endl; // false
    }
    // printElems.hpp Test
    {
        std::vector<std::string> words = {"hello", "world", "cpp"};
        printElems(words, 0, 2); // hello cpp 
    }
    // printIdx.hpp Test
    {
        std::vector<std::string> words = {"hello", "world", "cpp"};
        printIdx<0, 2>(words); // hello cpp
    }
    // Tuple
    {
        /*
        template<typename... _Elements>
            class tuple
        */
        std::tuple<int, std::string, char> v;
    }
    // Variant
    {
        /*
        template<typename... _Types>
            class variant
        */
        std::variant<int, std::string, char> v;
    }
    // printByIdx.hpp Test
    {
        std::tuple<int, std::string, char> v(42, "hello", 'x');
        printByIdx(v, Indices<0, 2>{}); // 42 x

        std::array<std::string, 5> arr = {"hello", "world", "cpp", "templates", "variadic"};
        printByIdx(arr, Indices<1, 3>{}); // world templates
    }
    // array
    {
        /*
        template<typename _Tp, typename... _Up>
            array(_Tp, _Up...)
            -> array<enable_if_t<(is_same_v<_Tp, _Up> && ...), _Tp>,
                1 + sizeof...(_Up)>;
        */
        std::array a{1, 2, 3};
    }
    // varusing.hpp Test
    {
        using CustomerOP = Overloader<CustomerHash, CustomerEq>;
        std::unordered_set<Customer, CustomerHash, CustomerEq> customers;
        std::unordered_set<Customer, CustomerOP, CustomerOP> customers2;
    }
    return 0;
}


#include "maxDefault.hpp"
#include "maxVal.hpp"
#include "maxRef.hpp"
#include "max5.hpp"
int main() {
    // maxDefault.hpp test
    {
        auto x1 = ::max(7, 42);    // Called max(int, int)
        std::cout << "max(7, 42) = " << x1 << std::endl; 
        auto x2 = ::max(7.0, 42.0);  // Called template max(T, T)
        std::cout << "max(7.0, 42.0) = " << x2 << std::endl;
        auto x3 = ::max('A', 'B');   // Called template max(T, T)    
        std::cout << "max('A', 'B') = " << x3 << std::endl;
        auto x4 = ::max<>(7, 42);    // Called template max(T, T)
        std::cout << "max<>(7, 42) = " << x4 << std::endl;
        auto x5 = ::max<double>(7.0, 42.0);   // Called template max(T, T)
        std::cout << "max<double>(7.0, 42.0) = " << x5 << std::endl;
        auto x6 = ::max('a', 42.7);   // Called max(int, int)
        std::cout << "max('a', 42.7) = " << x6 << std::endl;

        auto a = ::max2(7, 42.7);   // Called template max2(T1, T2)
        std::cout << "max2(7, 42.7) = " << a << std::endl;
        auto b = ::max2<long double>(7, 42.7);   // Called template max2(RT, T1, T2)
        std::cout << "max2<long double>(7, 42.7) = " << b << std::endl;

        // auto c = ::max2<int>(4, 7.2); // Error: template max2T1, T2) and template max2(RT, T1, T2) are both viable
        // std::cout << "max2(4, 7.2) = " << c << std::endl;

    }
    // maxVal.hpp test
    {
        int x = 7;
        int y = 42;
        auto p1 = ::max3(x, y);
        std::cout << "max3(x, y) = " << p1 << std::endl;

        std::string s1 = "hey";
        std::string s2 = "you";
        auto p2 = ::max3(s1, s2);
        std::cout << "max3(s1, s2) = " << p2 << std::endl;
        
        
        // int* p1 = &x;
        // int* p2 = &y;
        // auto p3 = ::max3(p1, p2); // 有三个重载 错误 template max3(T, T), template max3(T*, T*), non-template max3(const char*, const char*)
        // std::cout << "max3(p1, p2) = " << *p3 << std::endl;

        char const* a = "apple";
        char const* b = "banana";
        auto p4 = ::max3(a, b);
        std::cout << "max3(a, b) = " << p4 << std::endl;
    }
    // maxRef.hpp test
    {
        auto m1 = ::max4(7, 42, 68); // Called template max4(T const&, T const&, T const&)
        std::cout << "max4(7, 42, 68) = " << m1 << std::endl; // 不报错但是悬空引用！

        // char const* s1 = "apple";
        // char const* s2 = "banana";
        // char const* s3 = "pear";
        // auto m2 = ::max4(s1, s2, s3); // Error: Called template max4(T const&, T const&, T const&)
    }
    // max4.hpp test
    {
        auto m1 = ::max5(47, 11, 33); // Called template max5(T, T, T)
        std::cout << "max5(47, 11, 33) = " << m1 << std::endl;
    }
}
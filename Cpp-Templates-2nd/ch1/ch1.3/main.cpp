#include <iostream>
#include "func.hpp"
int main()
{
    // func.hpp test
    {
        int a = 10;
        double b = 20.5;
        auto result = max<int, double, double>(a, b);
        std::cout << "Max of " << a << " and " << b << " is " << result << std::endl;
        // 也可以这样写，指定返回的类型，而让编译器自动推导后两个模板参数的类型
        auto result2 = max2<double>(a, b);
        std::cout << "Max2 of " << a << " and " << b << " is " << result2 << std::endl;
        // 使用auto作为返回类型，让编译器自动推导所有模板参数的类型
        auto result3 = max3(a, b);
        std::cout << "Max3 of " << a << " and " << b << " is " << result3 << std::endl;
        // 使用尾置返回类型，让编译器自动推导所有模板参数的类型
        auto result4 = max4(a, b);
        std::cout << "Max4 of " << a << " and " << b << " is " << result4 << std::endl;
        // 使用尾置返回类型和true条件，让编译器自动推导所有模板参数的类型
        int& c = a;
        double& d = b;
        auto result5 = max5(c, d);
        std::cout << "Max5 of " << a << " and " << b << " is " << result5 << std::endl;
        // 使用decay去除引用和cv限定符
        const int& e = a;
        volatile double f = b;
        auto result6 = max6(e, f);
        std::cout << "Max6 of " << a << " and " << b << " is " << result6 << std::endl;

        int i = 42;
        int const& ir = i;
        auto aa = ir; // auto is decay: a is of type int

        // 使用common_type_t
        auto result7 = max7(e, f);
        std::cout << "Max7 of " << a << " and " << b << " is " << result7 << std::endl;
    }
}
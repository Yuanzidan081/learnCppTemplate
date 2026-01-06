#include <iostream>
#include "add.hpp"
#include "foo.hpp"
#include "getVal.hpp"
#include "cStyleCast.hpp"
int main()
{
    {
        int a = 5, b = 3;
        int result = add<int>(a, b);
        std::cout << "The sum of " << a << " and " << b << " is " << result << std::endl;
    }

    {
        int a = 5, b = 3;
        int result = add(a, b); // 自动推导
        std::cout << "The sum of " << a << " and " << b << " is " << result << std::endl;
    }

    {
        // int a = 5;
        // char b = 3;
        // int result = add(a, b); // 编译错误，类型不匹配

        A<int> a;
        int result = foo(a);
        std::cout << "Result from foo: " << result << std::endl;
    }

    {
        float a = getVal<float>(0);
        int b = getVal<int>(1);
        std::cout << "a = " << a << ", b = " << b << std::endl;
    }

    {
        int v = 1;
        float i = cStyleCast<int, float> (v);
        std::cout << "v = " << v << ", i = " << i << std::endl;
    }

    {
        int v = 2;
        float i = cStyleCast2<float>(v); // 需要指定的参数放在前面
        std::cout << "v = " << v << ", i = " << i << std::endl;
    }
    return 0;
}
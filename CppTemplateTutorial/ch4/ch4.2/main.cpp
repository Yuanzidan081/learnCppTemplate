#include <foo1.hpp>
#include <counter.hpp>
#include <counter2.hpp>
#include <counter3.hpp>
#include <counter4.hpp>
#include <foo2.hpp>
#include <foo3.hpp>
int main()
{
    // foo1.hpp test
    {
        foo<X>(10);    // Calls foo with type T::type
        foo<Y>(20);    // Calls foo with type T::type2
        foo<double>(30.5); // Calls foo with type T
    }
    // counter.hpp test
    {
        doSomething();
    }
    // counter2.hpp test
    {
        doSomething2();
    }
    // counter3.hpp test
    {
        doSomething3();
    }
    // counter4.hpp test Expression SFINAE
    {
        doSomething4();
    }
    // foo2.hpp test，限制参数为 float 类型
    {
        foo2(3.14f); // Calls foo2 with float
        float x = 2.71f;
        foo2(x);      // Calls foo2 with float
        // foo2(42);    // This would cause a compilation error due to SFINAE
        foo2_2(1.23f); // Calls foo2_2 with float rvalue
        x = 2.3f;
        // foo2_2(x); // Error, Calls foo2_2 with float rvalue!
    }
    // foo3.hpp test，参数无限制
    {
        foo3(100);          // Calls foo3 with int
        foo3(3.14);        // Calls foo3 with double
        float x = 2.71;
        foo3(x);           // Calls foo3 with float
    }
}
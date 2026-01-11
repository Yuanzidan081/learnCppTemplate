#include "func1.hpp"
#include "func2.hpp"
int main()
{
    {
        // func1.hpp 中的各种偏特化测试
        X<float *, int>::ToString();
        X<double *, int>::ToString();
        X<double, double>::ToString();
        X<float *, double *>::ToString();
        // X<float *, float *>::ToString(); // 错误
        X<double, float *>::ToString();
        X<int, double *>::ToString();
        // X<int *, int>::ToString(); // 错误
        X<double*, double>::ToString();        
    }

    {
        // func2.hpp 中的默认模板参数测试
        Y<int, float>::ToString();
        Y<int>::ToString();
    }
    return 0;
}
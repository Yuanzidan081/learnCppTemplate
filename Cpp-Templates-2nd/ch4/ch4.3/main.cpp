#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <string>
#include <complex>
void foo(int i, const char* s)
{
    std::cout << "foo: " << i << ", " << s << '\n';
}

struct Customer
{
    std::string firstName;
    std::string lastName;
    int birthYear;
    Customer(std::string fn, std::string ln, int by): firstName(fn), lastName(ln), birthYear(by) {}
};
int main()
{
    /*
    template<typename _Tp, typename... _Args>
    inline shared_ptr<_NonArray<_Tp>>
    make_shared(_Args&&... __args)
    {
        ...
    }
    */
    auto sp = std::make_shared<std::complex<float>>(4.2, 7.7);
    /*
    template<typename _Callable, typename... _Args,
        typename = _Require<__not_same<_Callable>>>
    explicit thread(_Callable&& __f, _Args&&... __args)
    {
        ...
    }
    */
    std::thread t(foo, 42, "hello");
    t.join();
    /*
    template <typename T, typename Allocator = allocator<T>>
    class vector
    {
    public:
        template<typename... _Args>
        reference emplace_back(_Args&&... __args);
    };
    */
    std::vector<Customer> customers;
    customers.emplace_back("John", "Smith", 1980);

    return 0;
}
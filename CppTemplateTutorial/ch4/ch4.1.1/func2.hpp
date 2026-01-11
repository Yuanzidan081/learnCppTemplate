template <typename T0, typename T1 = void>
struct Y
{
public:
    static void ToString()
    {
        std::cout << "Y<T0, T1>::ToString() called." << std::endl;
    }
};

template <typename T0> 
struct Y<T0>
{
public:
    static void ToString()
    {
        std::cout << "Y<T0>::ToString() called." << std::endl;
    }
};
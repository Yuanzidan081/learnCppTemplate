#include <iostream>
template <typename T0, typename T1 = void> struct DoWork;

template <typename T> struct DoWork<T> {
public:
    static void ToString()
    {
        std::cout << "DoWork<T>::ToString() called." << std::endl;
    }
};

template <> struct DoWork<int> {
public:
    static void ToString()
    {
        std::cout << "DoWork<int>::ToString() called." << std::endl;
    }
};

template <> struct DoWork<float> {
public:
    static void ToString()
    {
        std::cout << "DoWork<float>::ToString() called." << std::endl;
    }
};

template <> struct DoWork<int ,int> {
public:
    static void ToString()
    {
        std::cout << "DoWork<int, int>::ToString() called." << std::endl;
    }
};

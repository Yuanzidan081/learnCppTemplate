#include <iostream>
template <typename T1, typename T2>
class MyClass {
public:
    static void Print()
    {
        std::cout << "Primary template MyClass<T1, T2>" << std::endl;
    }
};

template <typename T>
class MyClass<T, T> {
public:
    static void Print()
    {
        std::cout << "Partial specialization MyClass<T, T>" << std::endl;
    }
};

template <typename T>
class MyClass<T, int> {
public:
    static void Print()
    {
        std::cout << "Partial specialization MyClass<T, int>" << std::endl;
    }
};

template <typename T1, typename T2>
class MyClass<T1*, T2*> {
public:
    static void Print()
    {
        std::cout << "Partial specialization MyClass<T1*, T2*>" << std::endl;
    }
};


template <typename T>
class MyClass<T*, T*> {
public:
    static void Print()
    {
        std::cout << "Partial specialization MyClass<T*, T*>" << std::endl;
    }
};


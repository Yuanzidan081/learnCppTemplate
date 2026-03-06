#include <iostream>

template <typename T>
struct MyClass;

template <typename T, std::size_t SZ>
struct MyClass<T[SZ]> // partial specialization for arrays of known bounds
{
    static void print() { std::cout << "print() for T[" << SZ << "]\n"; }
};

template <typename T, std::size_t SZ>
struct MyClass<T(&)[SZ]> // partial spec. for references to arrays of known bounds
{
    static void print() { std::cout << "print() for T(&)[" << SZ << "]\n"; }
};


template <typename T>
struct MyClass<T[]> // partial specialization for arrays of unknown bounds
{
    static void print() { std::cout << "print() for T[]\n"; }
};

template <typename T>
struct MyClass<T(&)[]> // partial specialization for references to arrays of unknown bounds
{
    static void print() { std::cout << "print() for T(&)[]\n"; }
};

template <typename T>
struct MyClass<T*> // partial specialization for pointers
{
    static void print() { std::cout << "print() for T*\n"; }
};

template <typename T1, typename T2, typename T3>
void foo(int a1[42], int a2[], // pointers by language rules
    int(&a3)[42], // reference to array of known bounds
    int(&a4)[], // reference to array of unknown bounds
    T1 a5, // passing by value decays
    T2& a6, T3&& a7) // passing by reference does not decay
{
    MyClass<decltype(a1)>::print(); // use MyClass<T*>
    MyClass<decltype(a2)>::print(); // use MyClass<T*>
    MyClass<decltype(a3)>::print(); // use MyClass<T(&)[SZ]>
    MyClass<decltype(a4)>::print(); // use MyClass<T(&)[]>
    MyClass<decltype(a5)>::print(); // use MyClass<T*>
    MyClass<decltype(a6)>::print(); // use MyClass<T(&)[]>
    MyClass<decltype(a7)>::print(); // use MyClass<T(&)[]>
}


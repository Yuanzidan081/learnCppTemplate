#include <iostream>
#include <memory>
template <typename T, typename U> struct X 
{
public:
    static void ToString()
    {
        std::cout << "X<T, U>::ToString() called." << std::endl;
    }
};

template <typename T> struct X<T, T> {
public:
    static void ToString()
    {
        std::cout << "X<T, T>::ToString() called." << std::endl;
    }
};

template<typename T> struct X<T*, T> {
public:
    static void ToString()
    {
        std::cout << "X<T*, T>::ToString() called." << std::endl;
    }   
};

template <typename T> struct X<T, T*> {
public:
    static void ToString()
    {
        std::cout << "X<T, T*>::ToString() called." << std::endl;
    }   
};

template <typename T> struct X<T, int> {
public:
    static void ToString()
    {
        std::cout << "X<T, int>::ToString() called." << std::endl;
    }   
};

template <typename T> struct X<T*, int> {
public:
    static void ToString()
    {
        std::cout << "X<T*, int>::ToString() called." << std::endl;
    }
};

template <typename T, typename U> struct X<T*, U*> {
public:
    static void ToString()
    {
        std::cout << "X<T*, U*>::ToString() called." << std::endl;
    }
};

template <typename T, typename U> struct X<T, U*> {
public:
    static void ToString()
    {
        std::cout << "X<T, U*>::ToString() called." << std::endl;
    }
};

template <typename T> struct X<std::unique_ptr<T>, std::shared_ptr<T>> {
public:
    static void ToString()
    {
        std::cout << "X<std::unique_ptr<T>, std::shared_ptr<T>>::ToString() called." << std::endl;
    }
};
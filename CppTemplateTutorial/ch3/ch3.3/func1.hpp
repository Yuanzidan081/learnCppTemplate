template <typename T> struct X
{
    
};

template <typename T> struct Y
{
    typedef X<T> ReboundTye;
    // typedef typename X<T>::MemberType MemberType; // 错误
    // typedef UnknownType MemberType3; // 错误

    void foo()
    {
        X<T> instance0;
        // typename X<T>::MemberType instance1;
        std::cout << "Y<T>::foo() called." << std::endl;
    }
};

struct A4;
template <typename T>
struct B4;

template <typename T>
struct X4
{
    typedef X4<T> TA;
    typedef X4 TB;
    typedef T TC;

    class Y
    {
        typedef X4<T> TD;
        typedef X4<T>::Y TE;
        // typedef X4<T*>::Y TG; // 错误，X<T*>和X<T>不一样，可能会在实例化的时候被别的偏特化给抢过去实现了
        typedef typename X4<T*>::Y TF;
    };

    typedef A4 TG;
    typedef B4<T> TH;
    // typedef B4<T>::MemberType TJ; // 错误，不知道B4<T>::type的信息
    typedef typename B4<T>::MemberType TI;

    // typedef B4<int>::type TJ; // 错误，B4还没有实现
};
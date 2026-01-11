// 声明和实现分离

struct A3;
template <typename T>
struct X3
{
    int v;
    void convertTo(A3& a);
};

struct A3
{
    int v;
};


template <typename T> void X3<T>::convertTo(A3& a)
{
    a.v = v;
}   
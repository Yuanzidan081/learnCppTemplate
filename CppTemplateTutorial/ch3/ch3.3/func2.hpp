struct A2;

struct A2
{
    int v;
};

template <typename T>
struct X2
{
    int v;
    void convertTo(A2& a)
    {
        a.v = v;
    }
};




template <typename T>
class AddFloatOrMulInt
{
public:
    static T Do(T a, T b) {
        return T(0);
    }
};

template <> class AddFloatOrMulInt<float>
{
public:
    static float Do(float a, float b) {
        return a + b;
    }
};

template <> class AddFloatOrMulInt<int>
{
public:
    static int Do(int a, int b) {
        return a * b;
    }
};
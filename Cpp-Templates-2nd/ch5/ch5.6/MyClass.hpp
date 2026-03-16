template <typename T>
class MyClass {
    public:
    static constexpr int max = 1000;
};

template <typename T>
int myMax = MyClass<T>::max;
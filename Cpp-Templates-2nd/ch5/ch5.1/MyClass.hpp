template <typename T>
class MyClass {
public:
    void foo()
    {
        typename T::SubType* ptr; // 必须加typename否则会认为*为乘法
    }
};
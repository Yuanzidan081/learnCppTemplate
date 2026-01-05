float data[1024];
template <typename T>
T getVal(int i)
{
    return static_cast<T>(data[i]);
}
#include <deque>
template <typename T, 
template <typename Elem> class Cont = std::deque>
// C++ 17以后也可以是template <typename Elem> typename Cont = std::deque> 
// 模板参数没有使用可以省略 template<typename> class Cont = std::deque>
class Stack8 {
private:
    Cont<T> elems;
public:
    void push(const T& elem);
    void pop() { elems.pop_back(); }
    T& top() { return elems.back(); }
    bool empty() const { return elems.empty(); }
}; 

template <typename T, 
template <typename> class Cont>
void Stack8<T, Cont>::push(const T& elem)
{
    elems.push_back(elem);
}
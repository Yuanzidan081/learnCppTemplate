#include <deque>
#include <cassert>
#include <memory>

template <typename T,
    template <typename Elem, typename = std::allocator<Elem>> 
    class Cont = std::deque>
class Stack9 {
private:
    Cont<T> elems;

public:
    void push(const T& elem);
    void pop();
    T& top();
    bool empty() const { return elems.empty(); }

    // assign stack of elements of type T2
    template <typename T2,
        template <typename Elem, typename = std::allocator<Elem>> 
        class Cont2>
    Stack9<T, Cont>& operator=(const Stack9<T2, Cont2>& other);

    template <typename, template <typename, typename> class>
    friend class Stack9;
};

template <typename T,
    template <typename Elem, typename> class Cont>
void Stack9<T, Cont>::push(const T& elem)
{
    elems.push_back(elem);
}

template <typename T,
    template <typename Elem, typename> class Cont>
void Stack9<T, Cont>::pop()
{
    assert(!elems.empty());
    elems.pop_back();
}

template <typename T,
    template <typename Elem, typename> class Cont>
T& Stack9<T, Cont>::top()
{
    assert(!elems.empty());
    return elems.back();
}

template <typename T,
    template <typename Elem, typename> class Cont>
template <typename T2,
    template <typename Elem, typename> class Cont2>
Stack9<T, Cont>& Stack9<T, Cont>::operator=(const Stack9<T2, Cont2>& other)
{
    elems.clear();
    elems.insert(elems.end(), other.elems.begin(), other.elems.end());
    return *this;
}
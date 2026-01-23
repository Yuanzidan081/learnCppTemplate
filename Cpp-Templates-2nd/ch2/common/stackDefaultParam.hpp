#include <vector>
#include <cassert>
#include <deque>

template <typename T, typename Cont = std::vector<T>>
class StackDefaultParam {
private:
    Cont elems;
public:
    StackDefaultParam() = default;
    StackDefaultParam(T const& elem) : elems({std::move(elem)}) {}
    StackDefaultParam(const StackDefaultParam&) = default;
    StackDefaultParam& operator=(const StackDefaultParam&) = default;
    void push(const T& elem);
    void pop();
    T const& top() const;
    bool empty() const {
        return elems.empty();
    }
};

template <typename T, typename Cont>
void StackDefaultParam<T, Cont>::push(const T& elem) {
    elems.push_back(elem);
}

template <typename T, typename Cont>
void StackDefaultParam<T, Cont>::pop() {
    assert(!elems.empty());
    elems.pop_back();
}

template <typename T, typename Cont>
T const& StackDefaultParam<T, Cont>::top() const {
    assert(!elems.empty());
    return elems.back();
}

template <typename T>
using DequeStack = StackDefaultParam<T, std::deque<T>>;
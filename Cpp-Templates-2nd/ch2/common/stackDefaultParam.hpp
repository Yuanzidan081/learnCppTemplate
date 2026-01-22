#include <vector>
#include <cassert>
#include <deque>

template <typename T, typename Cont = std::vector<T>>
class StackDaultParam {
private:
    Cont elems;
public:
    void push(const T& elem);
    void pop();
    T const& top() const;
    bool empty() const {
        return elems.empty();
    }
};

template <typename T, typename Cont>
void StackDaultParam<T, Cont>::push(const T& elem) {
    elems.push_back(elem);
}

template <typename T, typename Cont>
void StackDaultParam<T, Cont>::pop() {
    assert(!elems.empty());
    elems.pop_back();
}

template <typename T, typename Cont>
T const& StackDaultParam<T, Cont>::top() const {
    assert(!elems.empty());
    return elems.back();
}

template <typename T>
using DequeStack = StackDaultParam<T, std::deque<T>>;
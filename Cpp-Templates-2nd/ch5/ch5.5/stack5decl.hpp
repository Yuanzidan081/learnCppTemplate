#include <deque>
#include <stdexcept>
template <typename T>
class Stack {
private:
    std::deque<T> elems; // elements
public:
    void push(T const& elem) // push element
    {
        elems.push_back(elem); // append copy of passed element
    }
    void pop()          // pop element
    {
        if (elems.empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elems.pop_back(); // remove last element
    }
    T top() const      // return top element
    {
        if (elems.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems.back(); // return copy of last element
    }
    bool empty() const { // return true if empty.
        return elems.empty();
    }
    template <typename T2>
    Stack& operator=(Stack<T2> const&);
};


template <typename T>
template <typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& other) {
    Stack<T2> tmp(other);
    elems.clear();
    while (!tmp.empty())
    {
        elems.push_front(tmp.top());
        tmp.pop();
    }
    return *this;
}
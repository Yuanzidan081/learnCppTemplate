#include <deque>
#include <stdexcept>
template <typename T>
class Stack2 {
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
            throw std::out_of_range("Stack2<>::pop(): empty Stack2");
        }
        elems.pop_back(); // remove last element
    }
    T top() const      // return top element
    {
        if (elems.empty()) {
            throw std::out_of_range("Stack2<>::top(): empty Stack2");
        }
        return elems.back(); // return copy of last element
    }
    bool empty() const { // return true if empty.
        return elems.empty();
    }
    template <typename T2>
    Stack2& operator=(Stack2<T2> const&);

    template <typename> friend class Stack2;
};

template <typename T>
template <typename T2>
Stack2<T>& Stack2<T>::operator=(Stack2<T2> const& other) {
    elems.clear();
    elems.insert(elems.end(), other.elems.begin(), other.elems.end());
    return *this;
}
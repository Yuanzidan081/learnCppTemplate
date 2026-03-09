#include <deque>
#include <stdexcept>
template <typename T, typename Cont = std::deque<T>>
class Stack3 {
private:
    Cont elems; // elements
public:
    void push(T const& elem) // push element
    {
        elems.push_back(elem); // append copy of passed element
    }
    void pop()          // pop element
    {
        if (elems.empty()) {
            throw std::out_of_range("Stack3<>::pop(): empty Stack3");
        }
        elems.pop_back(); // remove last element
    }
    T top() const      // return top element
    {
        if (elems.empty()) {
            throw std::out_of_range("Stack3<>::top(): empty Stack3");
        }
        return elems.back(); // return copy of last element
    }
    bool empty() const { // return true if empty.
        return elems.empty();
    }
    template <typename T2, typename Cont2>
    Stack3& operator=(Stack3<T2, Cont2> const&);

    template <typename, typename> friend class Stack3;
};

template <typename T, typename Cont>
template <typename T2, typename Cont2>
Stack3<T, Cont>& Stack3<T, Cont>::operator=(Stack3<T2, Cont2> const& other) {
    elems.clear();
    elems.insert(elems.end(), other.elems.begin(), other.elems.end());
    return *this;
}
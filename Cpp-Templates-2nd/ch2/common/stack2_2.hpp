#include <vector>
#include <cassert>
#include <iostream>

template <typename T>
class Stack2 {
private:
    std::vector<T> elems; // elements
public:
    Stack2 () = default;                         // default constructor
    Stack2 (Stack2 const&) = default;            // copy constructor
    Stack2& operator= (Stack2 const&) = default; // copy assignment
    void push(T const&);  // push element
    void pop();           // pop element
    T top() const;        // return top element
    bool empty() const {  // return whether the stack is empty
        return elems.empty();
    }

    void printOn(std::ostream& strm) const
    {
        for (T const& elem : elems)
        {
            strm << elem << " ";
        }
    }
    template <typename U>
    friend std::ostream& operator<< (std::ostream& strm, Stack2<U> const& stack)
    {
        stack.printOn(strm);
        return strm;
    }
};

template <typename T>
void Stack2<T>::push(T const& elem) {
    std::cout << "Pushing element " << elem << " onto stack" << std::endl;
    elems.push_back(elem);
}

template <typename T>
void Stack2<T>::pop() {
    assert(!elems.empty());
    std::cout << "Popping element " << elems.back() << " from stack" << std::endl;
    elems.pop_back();
}

template <typename T>
T Stack2<T>::top() const {
    assert(!elems.empty());
    std::cout << "Returning top element " << elems.back() << " from stack" << std::endl;
    return elems.back();
}


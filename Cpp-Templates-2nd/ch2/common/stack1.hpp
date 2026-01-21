#include <vector>
#include <cassert>
#include <iostream>

template <typename T>
class Stack {
private:
    std::vector<T> elems; // elements
public:
    Stack () = default;                         // default constructor
    Stack (Stack const&) = default;            // copy constructor
    Stack& operator= (Stack const&) = default; // copy assignment
    void push(T const&);  // push element
    void pop();           // pop element
    T top() const;        // return top element
    bool empty() const {  // return whether the stack is empty
        return elems.empty();
    }
};

template <typename T>
void Stack<T>::push(T const& elem) {
    std::cout << "Pushing element " << elem << " onto stack" << std::endl;
    elems.push_back(elem);
}

template <typename T>
void Stack<T>::pop() {
    assert(!elems.empty());
    std::cout << "Popping element " << elems.back() << " from stack" << std::endl;
    elems.pop_back();
}

template <typename T>
T Stack<T>::top() const {
    assert(!elems.empty());
    std::cout << "Returning top element " << elems.back() << " from stack" << std::endl;
    return elems.back();
}


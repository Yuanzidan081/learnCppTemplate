#include <vector>
#include <cassert>
#include <iostream>

template <typename T>
class Stack {
private:
    std::vector<T> elems; // elements
public:
    Stack () = default;                         // default constructor
    Stack(T const& elem) :elems({std::move(elem)}) {} // initializer constructor
    Stack (Stack const&) = default;            // copy constructor
    Stack& operator= (Stack const&) = default; // copy assignment
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

template <>
void Stack<std::pair<int, int>>::push(std::pair<int, int> const& elem) {
    // std::cout << "Pushing element (" << elem.first << ", " << elem.second << ") onto stack" << std::endl;
    elems.push_back(elem);
}

template <>
void Stack<std::pair<int, int>>::pop() {
    assert(!elems.empty());
    std::pair<int, int> const& elem = elems.back();
    // std::cout << "Popping element (" << elem.first << ", " << elem.second << ") from stack" << std::endl;
    elems.pop_back();
}

template <>
std::pair<int, int> Stack<std::pair<int, int>>::top() const {
    assert(!elems.empty());
    std::pair<int, int> const& elem = elems.back();
    // std::cout << "Returning top element (" << elem.first << ", " << elem.second << ") from stack" << std::endl;
    return elem;
}


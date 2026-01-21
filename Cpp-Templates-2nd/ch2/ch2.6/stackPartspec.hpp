#include "stack1.hpp"

template <typename T>
class Stack<T*>
{
private:
    std::vector<T*> elems; // elements
public:
    Stack () = default;                         // default constructor
    Stack (Stack const&) = default;            // copy constructor
    Stack& operator= (Stack const&) = default; // copy assignment
    void push(T* const&);  // push element
    T* pop();           // pop element
    T* top() const;        // return top element
    bool empty() const {  // return whether the stack is empty
        return elems.empty();
    }
    void printOn(std::ostream& strm) const
    {
        for (T* const& elem : elems)
        {
            strm << *elem << " ";
        }
    }
    friend std::ostream& operator<< (std::ostream& strm, Stack<T*> const& stack)
    {
        stack.printOn(strm);
        return strm;
    }
};
template <typename T>
void Stack<T*>::push(T* const& elem) {
    std::cout << "[T*]Pushing element " << *elem << " onto stack" << std::endl;
    elems.push_back(elem);
}

template <typename T>
T* Stack<T*>::pop() {
    assert(!elems.empty());
    std::cout << "[T*]Popping element " << *(elems.back()) << " from stack" << std::endl;
    T* elem = elems.back();
    elems.pop_back();
    return elem;
}

template <typename T>
T* Stack<T*>::top() const {
    assert(!elems.empty());
    std::cout << "[T*]Returning top element " << *(elems.back()) << " from stack" << std::endl;
    return elems.back();
}
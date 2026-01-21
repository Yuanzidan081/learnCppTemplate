#include "stack1.hpp"
#include <string>
#include <deque>
template <>
class Stack<std::string> {
private:
    std::deque<std::string> elems; // elements
public:
    Stack () = default;                         // default constructor
    Stack (Stack const&) = default;            // copy constructor
    Stack& operator= (Stack const&) = default; // copy assignment
    void push(std::string const&);  // push element
    void pop();           // pop element
    std::string const& top() const;        // return top element
    bool empty() const {  // return whether the stack is empty
        return elems.empty();
    }

    void printOn(std::ostream& strm) const
    {
        for (std::string const& elem : elems)
        {
            strm << elem << " ";
        }
    }
    friend std::ostream& operator<< (std::ostream& strm, Stack<std::string> const& stack)
    {
        stack.printOn(strm);
        return strm;
    }
};

void Stack<std::string>::push(std::string const& elem) {
    std::cout << "[str]Pushing element " << elem << " onto stack" << std::endl;
    elems.push_back(elem);
}

void Stack<std::string>::pop() {
    assert(!elems.empty());
    std::cout << "[str]Popping element " << elems.back() << " from stack" << std::endl;
    elems.pop_back();
}

std::string const& Stack<std::string>::top() const {
    assert(!elems.empty());
    std::cout << "[str]Returning top element " << elems.back() << " from stack" << std::endl;
    return elems.back();
}
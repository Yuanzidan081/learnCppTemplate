#include <vector>
#include <cassert>
#include <iostream>

template <typename T>
class Stack3;
template <typename T>
std::ostream& operator<< (std::ostream& strm, Stack3<T> const& stack);

template <typename T>
class Stack3 {
private:
    std::vector<T> elems; // elements
public:
    Stack3 () = default;                         // default constructor
    Stack3 (Stack3<T> const&) = default;            // copy constructor
    Stack3& operator= (Stack3<T> const&) = default; // copy assignment
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
    friend std::ostream& operator<< <T>(std::ostream& strm, Stack3<T> const& stack);
};

template <typename T>
std::ostream& operator<< (std::ostream& strm, Stack3<T> const& stack)
{
    stack.printOn(strm);
    return strm;
}

template <typename T>
void Stack3<T>::push(T const& elem) {
    std::cout << "Pushing element " << elem << " onto stack" << std::endl;
    elems.push_back(elem);
}

template <typename T>
void Stack3<T>::pop() {
    assert(!elems.empty());
    std::cout << "Popping element " << elems.back() << " from stack" << std::endl;
    elems.pop_back();
}

template <typename T>
T Stack3<T>::top() const {
    assert(!elems.empty());
    std::cout << "Returning top element " << elems.back() << " from stack" << std::endl;
    return elems.back();
}


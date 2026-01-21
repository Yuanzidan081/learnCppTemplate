#include "stackPartSpec.hpp"
#include "MyClass.hpp"  
int main()
{
    // stackPartSpec.hpp test
    {
        Stack<int*> ptrStack;
        ptrStack.push(new int(42));
        std::cout << *ptrStack.top() << std::endl;
        delete ptrStack.pop();
    }

    // MyClass.hpp test
    {
        MyClass<int, double>::Print(); // Primary template
        MyClass<float, float>::Print();    // Partial specialization MyClass<T, T>
        MyClass<float, int>::Print();  // Partial specialization MyClass<T, int>
        MyClass<int*, double*>::Print(); // Partial specialization MyClass<T1*, T2*>
        // MyCalss<int, int>::Print(); // Error matches MyClass<T, T> and MyClass<T, int>
        MyClass<int*, int*>::Print(); // MyClass<T*, T*>
    }
    return 0;
}
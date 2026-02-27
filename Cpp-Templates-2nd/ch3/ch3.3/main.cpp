#include <iostream>
#include <string>
using namespace std;

template <double Val>
double process (double v)
{
    return v * Val;
}

/*
// Error class-type objects are not allowed as non-type template parameters
template <string name>
class StringWrapper
{

};
*/
template <char const* name>
class Message
{

};

extern char const s03[] = "hi";
char const s11[] = "hi";

template <int I, bool B>
class C {};

int main()
{
    double x = process<3.14>(2.0); // OK: 3.14 is a double literal
    cout << x << endl;
    Message<s03> m1; // OK: s03 has external linkage(all version)
    Message<s11> m2; // OK: s11 has internal linkage(since C++ 11)
    static char const s12[] = "hi";
    Message<s12> m3; // OK: s12 has no linkage(since C++ 17)

    
    C<sizeof(int) + 4, sizeof(int) == 4> c;
    C<42, (sizeof(int) > 4)> c2;
    return 0;
}
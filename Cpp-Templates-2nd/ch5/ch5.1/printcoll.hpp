#include <iostream>

/*
class stlContainer {
public:
    using iterator = ...; // iterator for read / write access
    using const_iterator = ...; // iterator for read-only access
};
*/
template <typename T>
void printcoll(T const& coll)
{
    typename T::const_iterator pos; // 必须加typename否则会认为::为作用域解析符
    typename T::const_iterator end(coll.end());
    for (pos = coll.begin(); pos != end; ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}
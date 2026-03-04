#include <string>
#include <unordered_set>    

class Customer
{
private:
    std::string name;
public:
    Customer(std::string n): name(n) {}
    std::string getName() const { return name; }
};

struct CustomerEq
{
    bool operator()(const Customer& c1, const Customer& c2) const
    {
        return c1.getName() == c2.getName();
    }
};

struct CustomerHash
{
    std::size_t operator()(const Customer& c) const
    {
        return std::hash<std::string>()(c.getName());
    }
};

template <typename... Bases>
struct Overloader: Bases...
{
    using Bases::operator() ...; // OK since C++ 17
};


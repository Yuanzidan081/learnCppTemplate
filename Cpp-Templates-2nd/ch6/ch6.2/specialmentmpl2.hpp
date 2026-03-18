#include <utility>
#include <string>
#include <iostream>

class Person
{
private:
    std::string name;
public:
    template <typename STR>
    explicit Person(STR&& name) : name(std::forward<STR>(name))
    {
        std::cout << "TEPL-CONSTR for " << this->name << std::endl;
    }

    Person(const Person& other) : name(other.name)
    {
        std::cout << "COPY-CONSTR for " << this->name << std::endl;
    }

    Person(Person&& other) noexcept : name(std::move(other.name))
    {
        std::cout << "MOVE-CONSTR for " << this->name << std::endl;
    }
};

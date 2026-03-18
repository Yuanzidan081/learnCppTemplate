#include "specialmentmpl2.hpp"
int main()
{
    std::string s = "Bob"; 
    Person p1("Alice");
    Person p2(s); 
    // Person p3(p2); // Error: char const[6]
    Person p4(std::move(p2)); // // OK: move Person => calls MOVE-CONST

    Person const p2c("ctmp");
    Person p3c(p2c); // OK: copy constant Person => calls COPY-CONSTR
    return 0;
}

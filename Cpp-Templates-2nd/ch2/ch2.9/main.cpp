#include <iostream>
#include <string>
#include "stack1.hpp"
#include "stackDefaultParam.hpp"
StackDefaultParam(const char*) -> StackDefaultParam<std::string>;
int main()
{
    // stackDeduce.hpp test
    {
        Stack intStack = 0; // StackDeduce<int>
        // StackDeduce stringStack = "bottom"; // Error! 字面值报错
    }
    // stackDefaultParam.hpp test
    {
        StackDefaultParam stringStack{"bottom"}; // StackDefaultParam<std::string>
        stringStack.push("middle");
        stringStack.push("top");
        // StackDefaultParam stringStack2 = "bottom"; // 不能讲字符串字面值char[]传转换为string传递
        Stack stack2{stringStack}; // StackDefaultParam<std::string>
        Stack stack3{stringStack};
        Stack stack4 = {stringStack};
        Stack stack5 = stringStack;
    }
    return 0;
}
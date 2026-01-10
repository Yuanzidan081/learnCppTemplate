#include <iostream>
#include "addFloatOrMulInt.hpp"
#include "TypeToID.hpp"
#include "copy.hpp"
#include "RemovePointer.hpp"
int main()
{
    {
        float f1 = 1.5f, f2 = 2.5f;
        int i1 = 3, i2 = 4;
    
        float floatResult = AddFloatOrMulInt<float>::Do(f1, f2);
        int intResult = AddFloatOrMulInt<int>::Do(i1, i2);
    
        std::cout << "Adding floats: " << f1 << " + " << f2 << " = " << floatResult << std::endl;
        std::cout << "Multiplying ints: " << i1 << " * " << i2 << " = " << intResult << std::endl;
    }
    {
        int uInt8ID = TypeToID<uint8_t>::ID;
        int intID = TypeToID<int>::ID;
        std::cout << "TypeToID<uint8_t>::ID = " << uInt8ID << std::endl;
        std::cout << "TypeToID<int>::ID = " << intID << std::endl;

        int floatNotID = TypeToID<float>::NotID;
        std::cout << "TypeToID<float>::NotID = " << floatNotID << std::endl;
        // int floatID = TypeToID<float>::ID; // 错误！特化没有继承关系
        // std::cout << "TypeToID<float>::ID = " << floatID << std::endl;

        std::cout << "ID of uint8_t*:" << TypeToID<TypeToID<uint8_t*>::SameAsT>::ID << std::endl; // 输出1
        int intPtrID = TypeToID<int*>::ID;
        std::cout << "TypeToID<int*>::ID = " << intPtrID << std::endl; // 模板是从最特殊到最一般形式进行匹配的
    }

    {
        const size_t elemCount = 5;
        int src[elemCount] = {1, 2, 3, 4, 5};
        int dst[elemCount] = {0};

        copy<int>(dst, src, elemCount);

        std::cout << "Copied array: ";
        for (size_t i = 0; i < elemCount; ++i) {
            std::cout << dst[i] << " ";
        }
        std::cout << std::endl;
    }

    {
        foo();
    }

    return 0;
}
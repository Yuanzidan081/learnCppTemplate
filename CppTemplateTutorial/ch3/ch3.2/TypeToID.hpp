#include "stdint.h"
template <typename T>
class TypeToID
{
public:
    static int const ID = -1;
};

template <> class TypeToID<uint8_t>
{
public:
    static int const ID = 1;
};

template <> class TypeToID<float>
{
public:
    static int const NotID = 2;
};

template <typename T>
class TypeToID<T*>
{
public:
    typedef T SameAsT;
    static int const ID = 3;
};

template <> class TypeToID<int*>
{
public:
    static int const ID = 4;
};

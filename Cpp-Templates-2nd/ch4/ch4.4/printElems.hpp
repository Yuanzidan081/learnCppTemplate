#pragma once
#include "print.hpp"

template <typename C, typename... Idx>
void printElems(C const& coll, Idx... idx)
{
    print(coll[idx]...);
}
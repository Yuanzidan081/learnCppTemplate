#pragma once
#include "print.hpp"

template <std::size_t... Idx, typename C>
void printIdx(C const& coll)
{
    print(coll[Idx]...);
}
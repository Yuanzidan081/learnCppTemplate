#pragma once
#include "print.hpp"
template <std::size_t...>
struct Indices
{};

template <typename T, std::size_t... Idx>
void printByIdx(T t, Indices<Idx...>)
{
    print(std::get<Idx>(t)...);
}

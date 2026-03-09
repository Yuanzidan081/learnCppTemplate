#include "boolstring.hpp"
// 必须加inline否则出错
template <>
inline bool BoolString::get<bool>() const {
    return value == "true" || value == "1" || value == "on";
}
#include <vector>
#include <string>
#include "vector_to_string.hpp"

template <>
std::string example::to_string(std::vector<std::string> const &v)
{
    std::string res;
    for (auto const &s : v) res += s + " ";
    res.erase(res.size()-1);
    return res;
}
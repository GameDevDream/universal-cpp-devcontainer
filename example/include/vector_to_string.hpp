#ifndef EXAMPLE_PRINT_VECTOR
#define EXAMPLE_PRINT_VECTOR

#include <vector>
#include <string>

namespace example
{
template <typename T>
std::string to_string(std::vector<T> const &v)
{
    std::string res = "std::vector{ ";
    for (auto const &i : v) res += to_string(i) + ", ";
    // res.replace();
    res += '}';
    return res;
}
}

#endif

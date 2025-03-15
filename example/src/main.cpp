#include <iostream>
#include <vector>
#include <string>
#include "vector_to_string.hpp"

int main() {
    std::vector<int> v1{ 1, 2, 3 };
    std::vector<std::vector<std::string>> {{"one", "two"}, {"apple, orange"}, {"I", "love", "C++"}};

    std::cout << example::to_string(v1) << '\n';
    std::cout << example::to_string(v2) << '\n';

    return 0;
}
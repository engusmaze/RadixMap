#include <iostream>
#include "radixmap.hpp"

int main()
{
    RadixMap<int> map;
    *map["test"] = 123456;
    std::cout << *map["test"] << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

void forIterTest()
{
    std::vector<int> vec{1, 2, 3, 4};
    auto itr = std::find(vec.begin(), vec.end(), 3);
    if (itr != vec.end())
        *itr = 4;
    for (auto element : vec)
    {
        std::cout << element << std::endl; // read only
    }
    for (auto &element : vec)
    {
        element += 1; // writeable
    }
    for (auto element : vec)
    {
        std::cout << element << std::endl; // read only
    }
}

int main()
{
    forIterTest();
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4};

    // 在c++17 之前
    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end())
    {
        *itr = 3;
    }

    // 需要重新定义一个新的变量
    const std::vector<int>::iterator itr2 = std::find(vec.begin(), vec.end(), 3);
    if (itr != vec.end())
    {
        *itr2 = 4;
    }

    // 将输出 1， 4， 3， 4
    for (std::vector<int>::iterator element = vec.begin(); element != vec.end(); element++)
    {
        std::cout << *element << std::endl;
    }
#if 0
    // 将临时变量放到 if 语句内, in C++ 17
    if (const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 3);
        itr != vec.end())
    {
        *itr = 4;
    }
#endif
    return 0;
}
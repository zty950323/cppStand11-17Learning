#include <initializer_list>
#include <vector>
#include <iostream>

class MagicFoo
{
  public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list)
    {
        // 从 C++11 起, 使用 auto 关键字进行类型推导
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            vec.push_back(*it);
        }
        // 在 C++11 之前
        // 由于 cbegin() 将返回 vector<int>::const_iterator
        // 所以 itr 也应该是 vector<int>::const_iterator 类型
        for (std::vector<int>::const_iterator itr = vec.cbegin(); itr != vec.cend(); ++itr)
        {
            std::cout << *itr << ", ";
        }
    }
};

int main()
{
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    std::cout << "magicFoo: ";
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    return 0;
}
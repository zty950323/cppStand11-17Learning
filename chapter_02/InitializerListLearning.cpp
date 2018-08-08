#include <iostream>
#include <vector>
#include <initializer_list>
class MagicFoo
{
  public:
    std::vector<int> vec;
    // 这种构造函数被叫做初始化列表构造函数，具有这种构造函数的类型将在初始化时被特殊关照。
    MagicFoo(std::initializer_list<int> list)
    {
        for (std::initializer_list<int>::iterator it = list.begin();
             it != list.end(); ++it)
            vec.push_back(*it);
    }
    // 初始化列表除了用在对象构造上，还能将其作为普通函数的形参
    void foo(std::initializer_list<int> list)
    {
        for (std::initializer_list<int>::iterator it = list.begin(); it != list.end(); ++it)
            vec.push_back(*it);
    }
};

class Foo
{
  public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b) {}
};

// 结构化绑定 In C++17
#if 0
std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 2.3, "456");
}
int main() {
    auto [x, y, z] = f();
    std::cout << x << ", " << y << ", " << z << std::endl;
    return 0;
}
#endif

int main()
{
    // before c++11
    int arr[3] = {1, 2, 3};
    Foo foo(1, 2);
    std::vector<int> vec{1, 2, 3, 4, 5};

    std::cout << "arr[0]: " << arr[0] << std::endl;
    std::cout << "foo." << foo.value_a << ", " << foo.value_b << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // after c++11
    MagicFoo magicFoo = {1, 2, 3, 4, 5};

    std::cout << "magicFoo: ";
    for (std::vector<int>::iterator it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    magicFoo.foo({6, 7, 8, 9});
    for (std::vector<int>::iterator it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}
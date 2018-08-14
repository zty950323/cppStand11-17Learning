#include <iostream>
#include <memory>

// 内存泄露的例子
struct A;
struct B;

struct A
{
  public:
    std::shared_ptr<B> pointer1;
    ~A()
    {
        std::cout << "A 被销毁" << std::end;
    }
};
struct B
{
  public:
    std::shared_ptr<A> pointer1;
    ~B()
    {
        std::cout << "B 被销毁" << std::end;
    }
};
void memoryLeakExample()
{
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a.pointer1 = b;
    b.pointer1 = a;
}

int main()
{
    return 0;
}
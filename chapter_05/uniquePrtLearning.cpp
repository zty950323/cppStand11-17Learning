#include <iostream>
#include <memory>

// make_unique 并不复杂，C++11 没有提供 std::make_unique，可以自行实现：

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

void uniquePtrTest()
{
    std::unique_ptr<int> pointer = std::make_unique<int>(10); // make_unique 从 C++14 引入
    // std::unique_ptr<int> pointer2 = pointer; // 非法
    std::cout << *pointer << std::endl;
}

struct Foo
{
    Foo() { std::cout << "Foo::Foo" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
    void foo() { std::cout << "Foo::foo" << std::endl; }
};

void f(const Foo &)
{
    std::cout << "f(const Foo &)" << std::endl;
}

void uniquePtrFooTest()
{
    std::unique_ptr<Foo> p1(std::make_unique<Foo>());
    // p1 不空， 输出
    if (p1)
        p1->foo();
    {
        std::unique_ptr<Foo> p2(std::move(p1));
        // p2 不空，输出
        f(*p2);
        // p2 不空，输出
        if (p2) p2->foo();
        // p1 不空， 输出
        if (p1) p1->foo();
        p1 = std::move(p2);
        // p2 为空， 无输出
        if (p2) p2->foo();
        std::cout << "p2 被销毁" << std::endl;
    }
    // p1 不空， 输出
    if (p1) p1->foo();
    // Foo 的实例会在离开作用域的时候被销毁。
}


int main()
{
    uniquePtrTest();
    uniquePtrFooTest();
    return 0;
}
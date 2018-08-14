#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> i)
{
    (*i)++;
}

void sharedPtrTest()
{
    // auto pointer = new int(10); // 非法，不允许直接赋值
    // 构造了一个std::shared_ptr
    auto pointer = std::make_shared<int>(10);
    foo(pointer);
    std::cout << *pointer << std::endl; // 11
    // 离开作用域钱， shared_ptr 会被析构，从而释放内存
}

void sharedGetTest()
{
    auto pointer = std::make_shared<int>(10);
    auto pointer2 = pointer;                                                      // 引用计数+1
    auto pointer3 = pointer;                                                      // 引用计数+1
    int *p = pointer.get();                                                       // 这样不会增加引用计数
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;    // 3
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;  // 3
    std::cout << "pointer3.user_count() = " << pointer3.use_count() << std::endl; // 3

    pointer2.reset();
    std::cout << "reset pointer2:" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;   // 2
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0, pointer2 已 reset
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2
    pointer3.reset();
    std::cout << "reset pointer3:" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;   // 1
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 0, pointer3 已 reset
}

int main()
{
    sharedPtrTest();
    sharedGetTest();
    return 0;
}
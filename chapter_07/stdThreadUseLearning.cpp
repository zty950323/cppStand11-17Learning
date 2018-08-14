#include <iostream>
#include <thread>
#include <mutex>

void foo()
{
    std::cout << "hello world" << std::endl;
}

void some_operation(const std::string &message)
{
    static std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);

    // ...操作

    // 当离开这个作用域的时候，互斥锁会被析构，同时unlock互斥锁
    // 因此这个函数内部的可以认为是临界区
}

int main()
{
    std::cout << "main thread enter." << std::endl;
    std::thread t(foo);
    t.join();
    return 0;
}
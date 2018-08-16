#include <iostream>
#include <thread>
#include <mutex>

int i = 0;

void foo()
{
    i++;
    std::cout << "hello world : " << i << std::endl;
}

void some_operation(const std::string &message)
{
    static std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);

    // ...操作

    // 当离开这个作用域的时候，互斥锁会被析构，同时unlock互斥锁
    // 因此这个函数内部的可以认为是临界区
}

std::mutex mtx;

void block_area() 
{
    ++i;
    std::unique_lock<std::mutex> lock(mtx);
    // ...临界区
    std::cout << "block_area enter" <<  std::endl;
    lock.unlock();
    // ... some other code
    std::cout << "block_area some other code." << std::endl;
    lock.lock(); // can lock again.
    std::cout << i << std::endl;
}



int main()
{
    i++;
    std::cout << "main thread enter. " << i << std::endl;
    std::thread t(foo);
    t.join();
    std::thread thd1(block_area);

    thd1.join();

    return 0;
}
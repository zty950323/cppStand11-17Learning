#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <queue>
#include <chrono>

void produce_costom()
{
    // 生产者数量
    std::queue<int> produced_nums;
    // 互斥锁
    std::mutex m;
    // 条件变量
    std::condition_variable cond_var;
    // 结束标志
    bool done = false;
    // 通知标志
    bool notified = false;

    // 生产者线程
    std::thread producer([&]() {
        for (int i = 0; i < 5; ++i)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            // 创建互斥锁
            std::unique_lock<std::mutex> lock(m);
            std::cout << "producing " << i << '\n';
            produced_nums.push(i);
            notified = true;
            // 通知一个线程
            cond_var.notify_one();
        }
        done = true;
        notified = true;
        cond_var.notify_one();
    });

    // 消费者线程
    std::thread consumer([&]() {
        std::unique_lock<std::mutex> lock(m);
        while (!done)
        {
            while (!notified)
            { // 循环避免虚假唤醒
                cond_var.wait(lock);
            }
            while (!produced_nums.empty())
            {
                std::cout << "consuming " << produced_nums.front() << '\n';
                produced_nums.pop();
            }
            notified = false;
        }
    });

    producer.join();
    consumer.join();
}

int main()
{
    produce_costom();
    return 0;
}
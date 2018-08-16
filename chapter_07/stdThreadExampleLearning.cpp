#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>

// "busy sleep" while suggesting that other threads run
// for a small amount of time.

void little_sleep(std::chrono::microseconds us)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + us;
    do
    {
        std::this_thread::yield();
    } while (std::chrono::high_resolution_clock::now() < end);
}

void yieldTestFunc()
{
    auto start = std::chrono::high_resolution_clock::now();

    little_sleep(std::chrono::microseconds(100));

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "waited for "
              << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
              << " microseconds\n";
}

std::mutex g_display_mutex;

void foo()
{
    std::thread::id this_id = std::this_thread::get_id();

    g_display_mutex.lock();
    std::cout << "thread " << this_id << " sleeping...\n";
    g_display_mutex.unlock();

    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void get_idTest() 
{
    std::thread t1(foo);
    std::thread t2(foo);

    t1.join();
    t2.join();
}

using namespace std::chrono_literals;

void foo_1() 
{
    std::this_thread::sleep_for(10ms);
}

void hash_threadidTest() 
{
    std::vector<std::thread> v;
    for(int n = 0; n < 4; ++n) 
    {
        v.emplace_back(foo_1);
    }

    std::hash<std::thread::id> hasher;
    for (auto& t : v) 
    {
        std::cout << "thread " << t.get_id() << " hashes to " << hasher(t.get_id()) << '\n';
        t.join();
    }
}

int main()
{
    yieldTestFunc();
    get_idTest();
    hash_threadidTest();
    return 0;
}
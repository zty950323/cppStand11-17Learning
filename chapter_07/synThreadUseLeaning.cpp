#include <iostream>
#include <future>
#include <thread>

void packaged_task()
{
    // 将一个返回值为7的 lambda表达式封装到 task 中
    // std::packaged_task 的模板参数为要封装函数的类型
    std::packaged_task<int()> task([]() { return 7; });
    // 获得 task 的 future
    std::future<int> result = task.get_future();    // 在一个线程中执行 task
    std::thread(std::move(task)).detach();
    std::cout << "Waiting...";
    result.wait();
    // 输出执行结果
    std::cout << "Done!" << std::endl << "Result is " << result.get() << '\n';
}

int main()
{
    packaged_task();
    return 0;
}
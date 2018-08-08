#include <iostream>
#include <utility>
#include <memory>
#include <functional>
#include <vector>
#include <string>

void learn_lambda_func_1()
{
    int value_1 = 1;
    auto copy_value_1 = [value_1] {
        return value_1;
    };
    value_1 = 100;
    auto stored_value_1 = copy_value_1();
    std::cout << stored_value_1 << std::endl;
    // 这时, stored_value_1 == 1, 而 value_1 == 100.
    // 因为 copy_value_1 在创建时就保存了一份 value_1 的拷贝

    auto add = [](auto x, auto y) {
        return x + y;
    };
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.1, 2.2) << std::endl;
}

void learn_lambda_func_2()
{
    int value_2 = 1;
    auto copy_value_2 = [&value_2] {
        return value_2;
    };
    value_2 = 100;
    auto stored_value_2 = copy_value_2();
    std::cout << stored_value_2 << std::endl;
    // 这时, stored_value_2 == 100, value_1 == 100.
    // 因为 copy_value_2 保存的是引用
}

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#if 1
void rightValueCaptureTest()
{
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
        return x + y + v1 + (*v2);
    };
    std::cout << add(3, 4) << std::endl;
}
#endif

using foo = void(int); // 定义函数指针, using 的使用见上一节中的别名语法
void functional(foo f)
{
    f(1);
}

void lambdaAsFooPtrTest()
{
    auto f = [](int value) {
        std::cout << value << std::endl;
    };

    functional(f); // 函数指针调用
    f(1);          // lambda表达式调用
}

int foo_(int para)
{
    return para;
}

void std_funcitonTest()
{
    // std::function 包装了一个返回值为 int， 参数为int 的函数
    std::function<int(int)> func = foo_;

    int important = 10;
    std::function<int(int)> func2 = [&](int value) -> int {
        return 1 + value + important;
    };
    std::cout << func(10) << std::endl;
    std::cout << func2(10) << std::endl;
}

int foo_1(int a, int b, int c)
{
    std::cout << a + b + c << std::endl;
    return 0;
}

void bind_placeholderTest()
{
    // 将参数1,2绑定到函数 foo 上，但是使用 std::placeholders::_1 来对第一个参数进行占位
    auto bindFoo = std::bind(foo_1, std::placeholders::_1, 1, 2);
    // 这时调用 bindFoo时候，只需要提供第一个参数就可以了
    bindFoo(1);
}

std::vector<int> foo_2()
{
    std::vector<int> temp = {1, 2, 3, 4};
    return temp;
}

void pureValueTest()
{
    std::vector<int> v = foo_2();
    for (std::vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }
}

void reference(std::string& str) {
    std::cout << "左值:" << str << std::endl;
}

void reference(std::string&& str) {
    std::cout << "右值:" << str << std::endl;
}

void leftValueTranToRightValueTest() {
    std::string lv1 = "string,"; // lv1是一个左值
    // std::string&& r1 = s1; // 非法, 右值引用不能引用左值
    std::string&& rv1 = std::move(lv1); // 合法，std::move可以将左值转移为右值
    std::cout << rv1 << std::endl; // string,

    const std::string& lv2 = lv1 + lv1; // 合法，常亮左值引用能够延长临时变量的生命周期
    // lv2 += "Test"; // 非法, 引用的右值无法被修改
    std::cout << lv2 << std::endl; // string,string

    std::string&& rv2 = lv1 + lv2; // 合法, 右值引用延长临时对象生命周期
    rv2 += "Test"; // 合法, 非常量引用能够修改临时变量
    std::cout << rv2 << std::endl;

    reference(rv2); // 输出左值

}

void avoidTheUselessCopyContructor() {
    std::string str = "Hello world.";
    std::vector<std::string> v;
    
    // 将使用 push_back(const T&), 即发生拷贝行为
    v.push_back(str);
    // 将输出 "str : Hello world."
    std::cout << "str: " << str << std::endl;

    // 将使用 push_back(const T&&), 不会发生拷贝行为
    // 而整个字符串被移动到 vector 中， 所以有时候 std::move 会用来减少拷贝出现的开销
    // 这步操作后， str 中的值会变为空
    v.push_back(std::move(str));
    // 将输出 "str : "
    std::cout << "str: " << str << std::endl;
}

int main()
{
    learn_lambda_func_1();
    learn_lambda_func_2();
    rightValueCaptureTest();
    lambdaAsFooPtrTest();
    std_funcitonTest();
    bind_placeholderTest();
    pureValueTest();
    leftValueTranToRightValueTest();
    avoidTheUselessCopyContructor();
    return 0;
}
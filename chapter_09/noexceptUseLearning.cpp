#include <iostream>
#include <string>

void may_throw()
{
    throw true;
}

auto non_block_throw = [] {
    may_throw();
};

void no_throw() noexcept
{
    return;
}

auto block_throw = []() noexcept
{
    no_throw();
};

// 字符串字面量自定义必须设置如下的参数列表
std::string operator"" _wow1(const char *wow1, size_t len) 
{
    return std::string(wow1) + "woooooooooow, amazing";
}

std::string operator"" _wow2 (unsigned long long i) {
return std::to_string(i)+"woooooooooow, amazing";
}

void wowTest() 
{
    auto str = "abc"_wow1;
    auto num = 1_wow2;
    std::cout << str << std::endl;
    std::cout << num << std::endl;
}

int main()
{
    std::cout << std::boolalpha << "may_throw() noexcept? " << noexcept(may_throw()) << std::endl
              << "no_throw() noexcept? " << noexcept(no_throw()) << std::endl
              << "lmay_throw() noexcept? " << noexcept(non_block_throw()) << std::endl
              << "lno_throw() noexcept? " << noexcept(block_throw()) << std::endl;

    try
    {
        may_throw();
    }
    catch (...)
    {
        std::cout << "捕获异常, 来自 may_throw()" << std::endl;
    }
    try
    {
        non_block_throw();
    }
    catch (...)
    {
        std::cout << "捕获异常, 来自 non_block_throw()" << std::endl;
    }
    try
    {
        block_throw();
    }
    catch (...)
    {
        std::cout << "捕获异常, 来自 block_throw()" << std::endl;
    }

    std::string str = R"(C:\\What\\The\\Fxxk)";
    std::cout << str << std::endl;
    wowTest();
    return 0;
}
#include <iostream>
#include <vector>
#include <map>

// 在C++11 之后，是允许下面这样嵌套>> 的代码的,
std::vector<std::vector<int>> matrix;

// 甚至下面的这种语法都是可以通过编译的
template <bool T>
class MagicType
{
    bool magic = T;
};

// 模板是用来产生类型的，模板不是类型，所以下面的语法是不合法的：
#if 0
template <typename T, typename U>
class MagicType_
{
  public:
    T dark;
    U magic;
};

template <typename T>
typedef MagicType<std::vector<T>, std::string> FakeDarkMagic;
#endif

// 通常我们使用 typedef 定义别名的语法是：typedef 原名称 新名称;，
// 但是对函数指针等别名的定义语法却不相同，这通常给直接阅读造成了一定程度的困难。
#if 0
typedef int (*process)(void *);
using NewProcess = int(*)(void *);
template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;
#endif

// 默认模板参数
// 定义了一个加法函数
template <typename T, typename U>
auto add(T x, U y) -> decltype(x + y)
{
    return x + y;
}

// 但在使用时发现，要使用 add，就必须每次都指定其模板参数的类型。

// 在 C++11 中提供了一种便利，可以指定模板的默认参数：

template <typename T = int, typename U = int>
auto add_(T x, U y) -> decltype(x + y)
{
    return x + y;
}

// 变长参数模板
// 在 C++11之前，无论是类模板还是函数模板，都只能按其指定的样子，接受一组固定数量的模板参数；
// 而 C++11 加入了新的表示方法，允许任意个数、任意类别的模板参数，同时也不需要再定义时将参数的个数固定。

template <typename... Ts>
class Magic;

// 如果不希望产生的模板参数个数为0，可以手动的定义至少一个模板参数：
template <typename Require, typename... Args>
class Magic_;
// 变长参数模板也能被直接调整到到模板函数上。
// 表示不定长模板参数外，函数参数也使用同样的表示法代表不定长参数，这也就为我们简单编写变长参数函数提供了便捷的手段，例如：
template <typename... Args>
void printf(const std::string &str, Args... args);

// 那么我们定义了变长的模板参数，如何对参数进行解包呢？
// 首先，我们可以使用 sizeof... 来计算参数的个数，：

template <typename... Args>
void magicFunc(Args... args)
{
    std::cout << sizeof...(args) << std::endl;
}
// 我们可以传递任意个参数给 magicFunc 函数：
void magicFuncTest()
{
    magicFunc();      // 输出0
    magicFunc(1);     // 输出1
    magicFunc(1, ""); // 输出2
}

// 其次，对参数进行解包，到目前为止还没有一种简单的方法能够处理参数包，但有两种经典的处理手法：

// template<typename T0>
// void printf_mm(T0 value) {
//     std::cout << value << std::endl;
// }
// template<typename T, typename... Args>
// void printf_m(T value, Args... args) {
//     std::cout << value << std::endl;
//     printf_mm(args...);
// }

// 1. 函数递归模板
// 递归是非常容易想到的一种手段，也是最经典的处理方法。
// 这种方法不断递归地向函数传递模板参数，进而达到递归遍历所有模板参数的目的：
template <typename T0>
void printf(T0 value)
{
    std::cout << value << std::endl;
}
template <typename T, typename... Args>
void printf(T value, Args... args)
{
    std::cout << value << std::endl;
    printf(args...);
}

void printf_test()
{
    printf(1, 2, "123", 1.1);
}

// // 你应该感受到了这很繁琐，在 C++17 中增加了变参模板展开的支持，于是你可以在一个函数中完成 printf 的编写：
// template <typename T0, typename... T>
// void printf_m_17(T0 t0, T... t)
// {
//     std::cout << t0 << std::endl;
//     if constexpr (sizeof...(t) > 0)
//         printf_m_17(t...);
// }

// 模板类 Magic 的对象，能够接受不受限制个数的 typename 作为模板的形式参数，例如下面的定义：
#if 0
class Magic<int,
            std::vector<int>,
            std::map<std::string,
                     std::vector<int> > > darkMagic;
#endif


int main()
{
    // in main function to call MagicType
    std::vector<MagicType<(1 > 2)>> magic; // 合法, 但不建议写出这样的代码
    //    TrueDarkMagic<bool> you;
    std::cout << add(10, 222.444) << std::endl;
    std::cout << add_(2, 5) << std::endl;
    std::cout << add_(2.42342, 343.5353) << std::endl;
    magicFuncTest();
    printf_test();
    return 0;
}
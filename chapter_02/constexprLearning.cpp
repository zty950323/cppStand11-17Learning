#include <iostream>
#define LEN 10

// In C++17 , if中使用constexpr，允许在代码中声明常量表达式的判断条件。
#if 0
template<typename T>
auto print_type_info(const T& t) {
    if constexpr (std::is_integral<T>::value) {
        return t + 1;
    } else {
        return t + 0.001;
    }
}

void test_if_constexpr() {
    std::cout << print_type_info(5) << std::endl;
    std::cout << print_type_info(3.14) << std::endl;
}

// 在编译的时候，实际代码会变现为如下：

int print_type_info(const int& t) {
    return t + 1;
}

double print_type_info(const double& t) {
    return t + 0.001;
}
#endif
int len_foo() {
    int i = 2;
    return i;
}

constexpr int len_foo_constexpr() {
    return 5;
}

constexpr int fibonacci(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

constexpr int fibonacci_cxx14(const int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    return fibonacci_cxx14(n - 1) + fibonacci_cxx14(n - 2);
}

int main() 
{
    char arr_1[10];                      // 合法
    char arr_2[LEN];                     // 合法

    int len = 10;
    // char arr_3[len];                  // 非法

    const int len_2 = len + 1;
    constexpr int len_2_constexpr = 1 + 2 + 3;
    // char arr_4[len_2];                // 非法, C++ 标准中数组的长度必须是一个常量表达式,len_2 是一个常数而不是一个常亮表达式
    char arr_4[len_2_constexpr];         // 合法

    // char arr_5[len_foo()+5];          // 非法
    char arr_6[len_foo_constexpr() + 1]; // 合法

    std::cout << fibonacci(10) << std::endl;
    // 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
    std::cout << fibonacci_cxx14(10) << std::endl;

    return 0;
}
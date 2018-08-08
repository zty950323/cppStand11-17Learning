#include <iostream>
// 编译这个代码需要开启 -std=c++14
template<typename T, typename... Args>
auto print(T value, Args... args) {
    std::cout << value << std::endl;
    return std::initializer_list<T>{([&] {
        std::cout << args << std::endl;
    }(), value)...};
}

template<typename ... T>
auto sum(T ... t) {
    return (t + ...);
}

int main() {
    print(1, 2.1, "123");
    std::cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
    return 0;
}
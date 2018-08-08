#include <iostream>

enum class new_enum : unsigned int
{
    value1,
    value2,
    value3 = 100,
    value4 = 100
};

// 而我们希望获得枚举值的值时，将必须显式的进行类型转换，
// 不过我们可以通过重载 << 这个算符来进行输出，可以收藏下面这个代码段：
template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e) 
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

int main()
{
    // 枚举值之间相同是可以比较的
    if (new_enum::value3 == new_enum::value4)
    {
        // 会输出
        std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
    }
    std::cout << new_enum::value3 << std::endl;
    std::cout << new_enum::value4 << std::endl;
    return 0;
}
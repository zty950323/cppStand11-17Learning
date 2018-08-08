#include <iostream>
#include <string>

void test()
{
    auto x = 1;
    auto y = 2;
    decltype(x + y) z;
    std::cout << z << std::endl;

    if (std::is_same<decltype(x), int>::value)
    {
        std::cout << "type x == int" << std::endl;
    }
    if (std::is_same<decltype(x), float>::value)
    {
        std::cout << "type x == flaot" << std::endl;
    }
    if (std::is_same<decltype(x), decltype(z)>::value)
    {
        std::cout << "type z == type x" << std::endl;
    }
}
// before c++11
template <typename R, typename T, typename U>
R add(T x, U y)
{
    return x + y;
}
// c++11
template <typename T, typename U>
auto add2(T x, U y) -> decltype(x + y)
{
    return x + y;
}

// c++14
template <typename T, typename U>
auto add3(T x, U y)
{
    return x + y;
}

void test2()
{
    // after c++11
    auto w = add2<int, double>(1, 2.0);
    if (std::is_same<decltype(w), double>::value)
    {
        std::cout << "w is double: ";
    }
    std::cout << w << std::endl;

    // after c++14
    auto q = add3<double, int>(1.0, 2);
    std::cout << "q: " << q << std::endl;
}

// c++14 decltype(auto) 一种略微复杂的用法
std::string lookup1() {
    return "lookupOne string.";
}
std::string str = "lookupTwo reference";
std::string &lookup2() {
    return str;
}

// in C++11 Implement a package from as follows:

std::string look_up_a_string_1()
{
    return lookup1();
}

std::string &look_up_a_string_2()
{
    return lookup2();
}

// in C++14 if we have the way of decltype(auto), we can make it easy
// to use compiler to do this annoying parameter forwarding

decltype(auto) look_up_a_string_1_14()
{
    return lookup1();
}

decltype(auto) look_up_a_string_2_14()
{
    return lookup2();
}

void test3() {
    std::cout << look_up_a_string_1() << std::endl;
    std::cout << look_up_a_string_2() << std::endl;
    std::cout << look_up_a_string_1_14() << std::endl;
}

int main()
{
    test();
    test2();
    return 0;
}
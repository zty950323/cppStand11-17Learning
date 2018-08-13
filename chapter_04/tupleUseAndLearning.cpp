#include <tuple>
#include <iostream>
#include <boost/variant.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

template <size_t n, typename... T>
boost::variant<T...> _tuple_index(size_t i, const std::tuple<T...> &tpl)
{
    if (i == n)
        return std::get<n>(tpl);
    else if (n == sizeof...(T) - 1)
        throw std::out_of_range("越界.");
    else
        return _tuple_index<(n < sizeof...(T) - 1 ? n + 1 : 0)>(i, tpl);
}
template <typename... T>
boost::variant<T...> tuple_index(size_t i, const std::tuple<T...> &tpl)
{
    return _tuple_index<0>(i, tpl);
}

template <typename T>
auto tuple_len(T &tpl)
{
    return std::tuple_size<T>::value;
}

auto get_student(int id)
{
    // 返回类型被推断为 std::tuple<double, char, std::string>

    if (id == 0)
    {
        return std::make_tuple(3.8, 'A', "张三");
    }
    if (id == 1)
    {
        return std ::make_tuple(2.9, 'C', "李四");
    }
    if (id == 2)
    {
        return std::make_tuple(1.7, 'D', "王五");
    }
    return std::make_tuple(0.0, 'D', "null");
    // 如果只写 0 会出现推断错误, 编译失败
}

void tupleTest()
{
    auto student = get_student(0);
    std::cout << "ID : 0, "
              << "GPA: " << std::get<0>(student) << " , "
              << "成绩： " << std::get<1>(student) << " , "
              << "姓名： " << std::get<2>(student) << "\n";

    double gpa;
    char grade;
    std::string name;

    // 进行元组拆包
    std::tie(gpa, grade, name) = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << gpa << ", "
              << "成绩: " << grade << ", "
              << "姓名: " << name << '\n';

    // 在C++14中，我们可以进行如下的操作
    std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);
    std::cout << std::get<std::string>(t) << std::endl;
    // std::cout << std::get<double>(t) << std::endl; // 非法, 引发编译期错误, 因为不确定是哪个double
    std::cout << std::get<3>(t) << std::endl;

    // 利用boost解决std::tuple get必须使用常量的问题
    int i = 1;
    std::cout << tuple_index(i, t) << std::endl;

    std::cout << "元组合并与遍历实验" << std::endl;
    auto new_tuple = std::tuple_cat(get_student(1), std::move(t));
    // 迭代
    for (int i = 0; i != tuple_len(new_tuple); ++i) 
    {
        // 运行期索引
        std::cout << tuple_index(i, new_tuple) << std::endl;
    }
}

int main()
{
    tupleTest();
    // 使用boost 获取日期进行库的测试
    boost::gregorian::date d(boost::gregorian::day_clock::local_day());
    std::cout << d.year() << d.month() << d.day() << std::endl;
    return 0;
}
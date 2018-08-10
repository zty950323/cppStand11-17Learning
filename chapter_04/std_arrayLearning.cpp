#include <iostream>
#include <array>
#include <algorithm>

void initArray()
{
    std::array<int, 4> arr = {1, 2, 3, 4};

    const int len = 4;
    // std::array<int, len> arr = {1,2,3,4}; // 非法, 数组大小参数必须是常量表达式
    std::array<int, len> arr_1 = {1, 2, 3, 4};
}

void foo(int *p, int len)
{
    for (int i = 0; i < len; ++i)
    {
        std::cout << *(p + i);
    }
    std::cout << std::endl;
    return;
}

void CInterfaceArrayUse()
{
    std::array<int, 4> arr = {1, 2, 3, 4};

    // C 风格接口传参数
    // foo(arr, arr.size()); // 非法, 无法隐式转换
    foo(&arr[0], arr.size());
    foo(arr.data(), arr.size());

    // 使用 std::sort
    std::sort(arr.begin(), arr.end());
    foo(arr.data(), arr.size());
}

int main()
{
    initArray();
    CInterfaceArrayUse();
    return 0;
}
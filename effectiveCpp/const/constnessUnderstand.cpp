#include "constnessUnderstand.h"
#include <iostream>

// 在真实生产环境中一般采用的是这样的方式来进行const 的相关的操作。
void print(const TextBlock &ctb) // 此函数中的ctb是const的
{
    std::cout << ctb[0]; // 调用 const TextBlock::operator[]
}

std::size_t CTextBlock::length() const 
{
    if (!lengthIsValid) 
    {
        // textLength = std::strlen(pText);    // 错误！ 在const成员函数内不能赋值给 textLength 和 lengthIsValid。
        // lengthIsValid = true;
    }
    return textLength;
}

int main()
{
    // 处理写入相应的对象的内容
    TextBlock tb("Hello");
    std::cout << tb[0]; // 调用 non-const TextBlock::operator[]
    tb[0] = 'X';
    std::cout << tb[0]; /// 正确，写入一个non-const TextBlock对象

    const TextBlock ctb("World");
    std::cout << ctb[0]; // 调用 const TextBlock::operator[]
    // ctb[0] = 'X'; 错误因为写了一个const TextBlock 

    print(TextBlock(".Panda!\n"));
    std::cout << std::endl;

    // 下面展示一种错误的演示，但是可以编译通过
    const CTextBlock cctb("Hello"); // 声明一个常量对象
    char* pc = &cctb[0];    // 调用 const operator[] 取得一个指针， 指向cctb的数据

    // *pc = 'J';  // cctb现在有了“Jello”这样的内容。// 这里会有段错误
    std::cout << *pc << std::endl; 

    return 0;
}
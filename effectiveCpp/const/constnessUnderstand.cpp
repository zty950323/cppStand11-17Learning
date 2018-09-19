#include "constnessUnderstand.h"
#include <iostream>

// 在真实生产环境中一般采用的是这样的方式来进行const 的相关的操作。
void print(const TextBlock &ctb) // 此函数中的ctb是const的
{
    std::cout << ctb[0]; // 调用 const TextBlock::operator[]
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

    return 0;
}
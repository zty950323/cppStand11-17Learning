#include <iostream>

class Base
{
  public:
    int value1;
    int value2;
    Base()
    {
        value1 = 1;
    }
    Base(int value) : Base()
    { // 委托 Base() 构造函数
        value2 = value;
    }
};

int main()
{
    Base b(2);
    std::cout << b.value1 << std::endl;
    std::cout << b.value2 << std::endl;
}
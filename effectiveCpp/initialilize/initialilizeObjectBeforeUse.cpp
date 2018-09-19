#include "initialilizeObjectBeforeUse.h"
#include <iostream>

void initialInnerType() 
{
    int x = 0;  // 对 int 进行手工初始化
    const char* text = "A C-style string";  // 对指针进行手工初始化

    double d;
    std::cin >> d;
    std::cout << x << '\t' << text << '\t' << d << std::endl;
}

ABEntry::ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones) 
{
    theName = name;     // 这些都是赋值(assignments)
    theAddress = address;   // 而非初始化 (initializations)
    thePhones = phones;
    numTimesConsulted = 0;
}

int main() 
{
    initialInnerType();
    return 0;
}
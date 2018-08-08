#include <iostream>

// SubClass::foo 可能并不是程序员尝试重载虚函数，只是恰好加入了一个具有相同名字的函数。
// 另一个可能的情形是，当基类的虚函数被删除后.
// 子类拥有旧的函数就不再重载该虚拟函数并摇身一变成为了一个普通的类方法，这将造成灾难性的后果。

// struct Base
// {
//     virtual void foo();
// };
// struct SubClass : Base
// {
//     void foo();
// };

// 当重载虚函数时，引入 override 关键字将显式的告知编译器进行重载，编译器将检查基函数是否存在这样的虚函数，否则将无法通过编译：
class Base_
{
  protected:
    inline virtual void foo(int)
    {
        std::cout << "Base_Foo" << std::endl;
    }
};
class SubClass_ : Base_
{
  public:
    inline virtual void foo(int) override
    {
        std::cout << "SubClass foo out." << std::endl;
    } // 合法
    // virtual void foo(float) override; // 非法, 父类没有此虚函数
};

struct Base_1
{
    virtual void Turing() = 0;
    virtual void Dijkstra() = 0;
    virtual void VNeumann(int g) = 0;
    virtual void DKnuth() const;
    void Print();
};

void Base_1::DKnuth() const
{
    std::cout << "DKnuth" << std::endl;
}

void Base_1::Print()
{
    std::cout << "Print" << std::endl;
}

struct DerivedMid : public Base_1
{
    // void VNeumann(double g);
    //接口被隔离了，曾想多一个版本的VNeumann函数
};

struct DerivedTop : public DerivedMid
{
    virtual void Turing() override;
    virtual void Dijkstra() override;
    virtual void VNeumann(int g) override;
    virtual void DKnuth() const override;
    // void Dikjstra() override;         //无法通过编译，拼写错误，并非重载
    // void VNeumann(double g) override; //无法通过编译，参数不一致，并非重载
    // void DKnuth() override;           //无法通过编译，常量性不一致，并非重载
    // void Print() override;            //无法通过编译，非虚函数重载
};

void DerivedTop::Turing()
{
    std::cout << "Turing" << std::endl;
}
void DerivedTop::Dijkstra()
{
    std::cout << "Dijkstra" << std::endl;
}
void DerivedTop::VNeumann(int g)
{
    std::cout << "VNeumann " << g << std::endl;
}

void DerivedTop::DKnuth() const
{
    std::cout << "DKnuth " << std::endl;
}

// final 则是为了防止类被继续继承以及终止虚函数继续重载引入的。
struct Base_final
{
    virtual void foo() final
    {
        std::cout << "Base foo final" << std::endl;
    }
};
struct SubClass1 final : Base_final
{
}; // 合法
#if 0
struct SubClass2 : SubClass1 {
}; // 非法, SubClass1 已 final

struct SubClass3: Base_final {
void foo(); // 非法, foo 已 final
};
#endif

// C++11 允许显式的声明采用或拒绝编译器自带的函数。

class Magic {
    public:
    Magic() = default; // 显式声明使用编译器生成的构造
    Magic& operator=(const Magic&) = delete; // 显式声明拒绝编译器生成构造
    Magic(int magic_number) 
    {
        std::cout << magic_number << std::endl;
    }
};

int main()
{
    Base_1 *dp = new DerivedTop;
    dp->Turing();
    dp->Dijkstra();
    dp->VNeumann(10);
    dp->DKnuth();
    SubClass_ *s = new SubClass_;
    s->foo(1);
    SubClass1 *s1 = new SubClass1;
    s1->foo();

    Magic m(100);

    return 0;
}
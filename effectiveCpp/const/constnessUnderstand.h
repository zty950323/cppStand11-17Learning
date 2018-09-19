#include <string>

class TextBlock
{
  public:
    explicit TextBlock(std::string str) : text(str) {}
    // 请注意，下面的返回对象 non-const 是一个reference to char， 不是 char， 如果是复制的话，那么是不能对其进行操作的。
    const char &operator[](std::size_t position) const // operator[] for const 对象
    {
        return text[position];
    }
    char &operator[](std::size_t position) // operator[] for non-const对象
    {
        return text[position];
    }

  private:
    std::string text;
};

//  假设我们有一个TextBlock-like class
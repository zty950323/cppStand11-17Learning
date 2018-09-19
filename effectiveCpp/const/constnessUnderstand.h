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
class CTextBlock
{
  public:
    std::size_t length() const;
    explicit CTextBlock(char *str) : pText(str) {}
    char &operator[](std::size_t position) const // bitwise const 声明，
    {
        return pText[position];
    } // 但其实不适当
  private:
    char *pText;
    std::size_t textLength; // 最近一次计算的文本区块长度
    bool lengthIsValid;     // 目前长度是否有效
};

class WPTextBlock
{
  public:
    const char operator[](std::size_t position) const
    {
        // 边界检验 (bounds checking)
        // 志记数据访问 (log access data)
        // 检验数据完整性 (verify data integrity)
        return text[position];
    }
    char &operator[](std::size_t position)
    {
        // 边界检验 (bounds checking)
        // 志记数据访问 (log access data)
        // 检验数据完整性 (verify data integrity)
        return text[position];
    }

  private:
    std::string text;
};

class RPTextBlock
{
  public:
    const char &operator[](std::size_t position) const // 一如既往
    {
        // 边界检验 (bounds checking)
        // 志记数据访问 (log access data)
        // 检验数据完整性 (verify data integrity)
        return text[position];
    }

    char &operator[](std::size_t position) // 现在只调用 const op[]

    {
        return const_cast<char &>(
            static_cast<const RPTextBlock &>(*this)[position]);
    }

  private:
    std::string text;
};
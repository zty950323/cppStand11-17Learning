#include <list>
#include <string>

void initialInnerType();

class PhoneNumber
{
    //
};

class ABEntry
{ // ABEntry = "Address Book Entry"
  public:
    ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> &phones);

  private:
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
    int numTimesConsulted;
};
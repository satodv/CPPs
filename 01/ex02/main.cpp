#include <iostream>
#include <string>

// void checkAddress(const void* addr1, const void* addr2, const char* name1, const char* name2) {
//     std::cout << name1 << ": " << addr1 << std::endl;
//     std::cout << name2 << ": " << addr2 << std::endl;
//     std::cout << "Are they equal? " << (addr1 == addr2 ? "YES" : "NO") << std::endl;
// }

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout   << "String address:    " << &str << std::endl
                << "StringPTR address: " << stringPTR << std::endl
                << "StringREF address: " << &stringREF << std::endl
                << "String value:    " << str << std::endl
                << "StringPTR value: " << *stringPTR << std::endl
                << "StringREF value: " << stringREF << std::endl;

    /*
    std::cout
                << "Are the addresses str and strPTR equal? " << (&str == stringPTR ? "YES" : "NO") << std::endl
                << "Are the addresses str and strREF equal? " << (&str == &stringREF ? "YES" : "NO") << std::endl;
    checkAddress(static_cast<const void*>(&str),
    static_cast<const void*>(stringPTR),
    "&str (object address)", "stringPTR (points to)");
    
    checkAddress(static_cast<const void*>(stringPTR),
    static_cast<const void*>(&stringPTR),
    "stringPTR (points to)", "&stringPTR (pointer variable)");
    */
    return 0;
}

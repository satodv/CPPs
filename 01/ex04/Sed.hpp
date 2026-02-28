#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class SedBuilt {
private:
    std::string filename;
    std::string s1;
    std::string s2;

public:
    SedBuilt(std::string filename, std::string s1, std::string s2);
    bool process();
};

#endif

#include "Sed.hpp"

SedBuilt::SedBuilt(std::string filename, std::string s1, std::string s2)
    : filename(filename), s1(s1), s2(s2) {}

bool SedBuilt::process() {
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file.\n";
        return false;
    }

    std::string outFileName = filename + ".replace";
    std::ofstream outFile(outFileName.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create output file.\n";
        return false;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outFile << line << '\n';
    }

    inFile.close();
    outFile.close();
    return true;
}

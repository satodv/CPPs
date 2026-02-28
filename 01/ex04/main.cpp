#include "Sed.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "./sed <filename> <string 1> <string 2>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 (string to replace) cannot be empty.\n";
        return 1;
    }

    SedBuilt replacer(filename, s1, s2);
    if (!replacer.process()) {
        std::cerr << "Error: Could not process the file.\n";
        return 1;
    }

    return 0;
}

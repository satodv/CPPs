#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain(std::string level) {
    void (Harl::*func[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*func[i])();
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::debug() {
    std::cout << "[ DEBUG ]\n"
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" 
              << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]\n"
              << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" 
              << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]\n"
              << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
              << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]\n"
              << "This is unacceptable! I want to speak to the manager now." 
              << std::endl;
}

#include "Harl.hpp"
#include <iostream>

void Harl::complain(std::string level) {
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string cmd[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	for ( ; i < 4 ; i++) {
		if (cmd[i] == level) {
			break ;
		}
	}
	switch (i)
	{
	case 0:
		(this->*f[0])();
	case 1:
		(this->*f[1])();
	case 2:
		(this->*f[2])();
	case 3:
		(this->*f[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]\n" 
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
	<< "I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]\n"
	<< "I cannot believe adding extra bacon costs more money.\n"
	<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]\n"
	<< "I think I deserve to have some extra bacon for free.\n"
	<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error (void) {
	std::cout << "[ ERROR ]\n"
	<< "This is unacceptable! I want to speak to the manager now" << std::endl;
}
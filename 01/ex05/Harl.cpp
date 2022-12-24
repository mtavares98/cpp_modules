#include "Harl.hpp"



void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

Harl::Harl(void)
{
	std::cout << "Called default constructor\n";
	this->func[0].name = "DEBUG";
	this->func[0].action = &Harl::debug;
	this->func[1].name= "INFO";
	this->func[1].action = &Harl::info;
	this->func[2].name= "WARNING";
	this->func[2].action = &Harl::warning;
	this->func[3].name= "ERROR";
	this->func[3].action = &Harl::error;
}

Harl::~Harl(void)
{
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++) {
		if (this->func[i].name == level) {
			(this->*func[i].action)();
			return ;
		}
	}
}

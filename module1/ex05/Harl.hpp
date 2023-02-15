#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	typedef struct func {
		std::string name;
		void (Harl::*action)(void);
	}t_func;

	private:
		t_func func[4];
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
};
#endif

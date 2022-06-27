#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
public:
   Brain();
   Brain(const Brain &obj);
   Brain &operator=(const Brain &obj);
   ~Brain();
private:
	std::string ideas_[100];
};

#endif
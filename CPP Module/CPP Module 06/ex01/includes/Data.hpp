#ifndef DATA_HPP
# define DATA_HPP

#include <string>

struct Data
{
	Data();
	Data(std::string prefix, int random, std::string suffix);
	Data(const Data &rhs);
	Data &operator=(const Data &rhs);
	~Data();
	void print();
	std::string prefix_;
	int random_;
	std::string suffix_;
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif

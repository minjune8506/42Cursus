#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define SPECIAL 4

class Convert {
public:
	Convert(std::string str);
	Convert(const Convert &obj);
	Convert &operator=(const Convert &obj);
	~Convert();
	void charType();
	void intType();
	void doubleType();
	void floatType();
	void checkType();
	void specialType();
	void print();

private:
	Convert();
	int i_;
	char c_;
	float f_;
	double d_;
	int type_;
	std::string str_;
	std::string intErr_;
	std::string charErr_;
	std::string doubleErr_;
	std::string floatErr_;
};

#endif
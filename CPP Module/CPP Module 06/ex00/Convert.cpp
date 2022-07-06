#include "Convert.hpp"
#include <iostream>
#include <cstring>

Convert::Convert() {
	std::cout << "Forbidden" << std::endl;
}

void Convert::checkType() {
	std::string doubleValues[] = {"+inf", "-inf", "nan"};
	size_t dot_pos = str_.find('.');
	size_t f_pos = str_.find('f');

	if (str_.size() > 10) {
		type_ = DOUBLE;
		return ;
	}

	// CHAR (size = 1, range)
	if (str_.size() == 1 && !isnumber(str_[0]) && std::numeric_limits<char>::min() <= str_[0] && std::numeric_limits<char>::max() >= str_[0]) {
		type_ = CHAR;
		return ;
	}
	
	// Float, Double Special Types
	for (int i = 0 ; i < str_.size() ; i++) {
		if (doubleValues[i] == str_) {
			doubleErr_ = doubleValues[i];
			type_ = SPECIAL;
			return ;
		}
	}

	// Float, Double ('.', 'f')
	if (dot_pos != std::string::npos || f_pos != std::string::npos) {
		if (f_pos != std::string::npos) {
			// type_ = FLOAT;
			type_ = DOUBLE;
			return ;
		}
		type_ = DOUBLE;
		return ;
	}

	type_ = INT;
	return ;
}

Convert::Convert(std::string str) : str_(str) {
	checkType();
	std::cout << "type_ : " << type_ << std::endl;
	switch (type_)
	{
	case CHAR:
		charType();
		break;
	case INT:
		intType();
		break;
	// case FLOAT:
	// 	floatType();
	// 	break;
	case DOUBLE:
		doubleType();
		break;
	case SPECIAL:
		specialType();
		break;
	}
}

Convert::Convert(const Convert &obj) {
	*this = obj;
}

Convert &Convert::operator=(const Convert &obj) {
	i_ = obj.i_;
	c_ = obj.c_;
	d_ = obj.d_;
	f_ = obj.f_;
	type_ = obj.type_;
	str_ = obj.str_;
	intErr_ = obj.intErr_;
	charErr_ = obj.charErr_;
	doubleErr_ = obj.doubleErr_;
	floatErr_ = obj.floatErr_;
	return (*this);
}

Convert::~Convert() {

}

void Convert::charType() {
	if (!isprint(str_[0])) {
		charErr_ = "Non displayable";
	}
	c_ = str_[0];
	i_ = static_cast<int>(c_);
	f_ = static_cast<float>(c_);
	d_ = static_cast<double>(c_);
}

void Convert::intType() {
	long long temp = atoll(str_.c_str());
	if (str_.size() > 11 || temp > std::numeric_limits<int>::max()
	 || temp < std::numeric_limits<int>::min()) {
		intErr_ = "impossible";
		charErr_ = "impossible";
	}
	if (temp > std::numeric_limits<char>::max() || temp < std::numeric_limits<char>::min()) {
		charErr_ =  "impossible";
	}
	c_ = static_cast<char>(temp);
	i_ = static_cast<int>(temp);
	f_ = static_cast<float>(temp);
	d_ = static_cast<double>(temp);
}

void Convert::doubleType() {
	d_ = atof(str_.c_str());
	if (d_ == std::numeric_limits<double>::infinity()) {
		doubleErr_ = "+inf";
		floatErr_ = "+inff";
		intErr_ = "impossible";
		charErr_ = "impossible";
	}
	else if (d_ == -std::numeric_limits<double>::infinity()) {
		doubleErr_ = "-inf";
		floatErr_ = "-inff";
		intErr_ = "impossible";
		charErr_ = "impossible";
	}
	else if (isnan(d_)) {
		doubleErr_ = "nan";
		floatErr_ = "nanf";
		intErr_ = "impossible";
		charErr_ = "impossible";
	} else if (d_ > std::numeric_limits<float>::max() || d_ < -std::numeric_limits<float>::max()) {
		floatErr_ = "impossible";
		intErr_ = "impossible";
		charErr_ = "impossible";
	}
	else if (d_ > std::numeric_limits<int>::max() || d_ < std::numeric_limits<int>::min()) {
		intErr_ = "impossible";
		charErr_ = "impossible";
	}
	else if (d_ > std::numeric_limits<char>::max() || d_ < std::numeric_limits<char>::min()) {
		charErr_ = "impossible";
	}
	f_ = static_cast<float>(d_);
	i_ = static_cast<int>(d_);
	c_ = static_cast<char>(d_);
}

void Convert::floatType() {
	d_ = atof(str_.c_str());
	if (d_ == std::numeric_limits<float>::infinity()) {
		floatErr_ = "+inf";
	}
	else if (d_ == -std::numeric_limits<float>::infinity()) {
		floatErr_ = "-inf";
	}
	else if (isnan(d_)) {
		floatErr_ = "nan";
	}

	if (d_ > std::numeric_limits<float>::max() || d_ < std::numeric_limits<float>::min()) {
		floatErr_ = "impossible";
		intErr_ = "impossible";
		charErr_ = "impossible";
	} else if (d_ > std::numeric_limits<int>::max() || d_ < std::numeric_limits<int>::min()) {
		intErr_ = "impossible";
		charErr_ = "impossible";
	}
	else if (d_ > std::numeric_limits<char>::max() || d_ < std::numeric_limits<char>::min()) {
		charErr_ = "impossible";
	}
	f_ = static_cast<float>(d_);
	i_ = static_cast<int>(d_);
	c_ = static_cast<char>(d_);
}

void Convert::specialType() {
	charErr_ = "impossible";
	intErr_ = "impossible";

	if (floatErr_ == "+inff" || doubleErr_ == "+inf") {
		floatErr_ = "+inff";
		doubleErr_ = "+inf";
	} else if (floatErr_ == "-inff" || doubleErr_ == "-inf") {
		floatErr_ = "-inff";
		doubleErr_ = "-inff";
	} else if (floatErr_ == "nanf" || doubleErr_ == "nan") {
		floatErr_ = "nanf";
		doubleErr_ = "nan";
	}
}

void Convert::print() {
	std::cout << "char: ";
	if (charErr_.size()) {
		std::cout << charErr_ << std::endl;
	} else if (!isprint(c_)) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << c_ << std::endl;
	}
	std::cout << "int: ";
	if (intErr_.size()) {
		std::cout << intErr_ << std::endl;
	} else {
		std::cout << i_ << std::endl;
	}
	std::cout << "float: ";
	if (floatErr_.size()) {
		std::cout << floatErr_ << std::endl;
	} else {
		std::cout << f_;
		size_t pos = str_.find('f');
		if (pos != std::string::npos) {
			str_.erase(pos);
		}
		if (type_ == CHAR || type_ == INT || str_.find_last_of("0") == (str_.size() - 1)) {
			std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	}
	std::cout << "double: ";
	if (doubleErr_.size()) {
		std::cout << doubleErr_ << std::endl;
	} else {
		std::cout << d_;
		size_t pos = str_.find('f');
		if (pos != std::string::npos) {
			str_.erase(pos);
		}
		if (type_ == CHAR || type_ == INT || str_.find_last_of("0") == (str_.size() - 1)) {
			std::cout << ".0";
		}
		std::cout << std::endl;
	}
}
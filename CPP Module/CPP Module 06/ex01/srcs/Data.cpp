#include "Data.hpp"
#include <iostream>

Data::Data() : prefix_("prefix"), suffix_("suffix") {
	srand(time(0));
	random_ = rand();
}

Data::Data(std::string prefix, int random, std::string suffix)
: prefix_(prefix), random_(random), suffix_(suffix) {

}

Data::Data(const Data &rhs) : prefix_(rhs.prefix_), random_(rhs.random_), suffix_(rhs.suffix_) {

}

Data &Data::operator=(const Data &rhs) {
	prefix_ = rhs.prefix_;
	random_ = rhs.random_;
	suffix_ = rhs.suffix_;
	return (*this);
}

Data::~Data() {
	
}

void Data::print() {
	std::cout << "prefix : " << prefix_ << '\n'
	<< "random : " << random_ << '\n'
	<< "suffix : " << suffix_ << std::endl;
}

uintptr_t serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

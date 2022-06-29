#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource Constructor Called" << std::endl;
	for (int i = 0 ; i < 4 ; i++) {
		store_[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
	std::cout << "MateriaSource Constructor Called" << std::endl;
	for (int i = 0 ; i < 4 ; i++) {
		store_[i] = NULL;
		if (obj.store_[i]) {
			store_[i] = obj.store_[i]->clone();
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj) {
	for (int i = 0; i < 4; i++) {
		delete store_[i];
		store_[i] = NULL;
		if (obj.store_[i]) {
			store_[i] = obj.store_[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0 ; i < 4 ; i++) {
		delete store_[i];
		store_[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *obj) {
	for (int i = 0 ; i < 4 ; i++) {
		if (!store_[i]) {
			store_[i] = obj;
			break ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0 ; i < 4 ; i++) {
		if (store_[i] && store_[i]->getType() == type) {
			return store_[i]->clone();
		}
	}
	return 0;
}

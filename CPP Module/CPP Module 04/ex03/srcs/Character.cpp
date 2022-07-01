#include "Character.hpp"
#include "Ice.hpp" 
#include "Cure.hpp"
#include <iostream>

Character::Character() {
	for (int i = 0 ; i < 4 ; i++) {
		slot_[i] = NULL;
	}
}

Character::Character(const std::string name) : name_(name) {
	for (int i = 0 ; i < 4 ; i++) {
		slot_[i] = NULL;
	}
}

Character::Character(const Character &obj) {
	for (int i = 0 ; i < 4 ; i++) {
		slot_[i] = NULL;
	}
	for (int i = 0 ; i < 4 ; i++) {
		if (!obj.slot_[i]) {
			continue;
		}
		slot_[i] = obj.slot_[i]->clone();
	}
	name_ = obj.name_;
}

Character &Character::operator=(const Character &obj) {
	for (int i = 0 ; i < 4 ; i++) {
		delete slot_[i];
		slot_[i] = NULL;
		if (!obj.slot_[i]) {
			continue;
		}
		slot_[i] = obj.slot_[i]->clone();
	}
	name_ = obj.name_;
	return (*this);
}

Character::~Character() {
	for (int i = 0 ; i < 4 ; i++) {
		delete slot_[i];
		slot_[i] = NULL;
	}
}

std::string const &Character::getName() const {
	return name_;
}

void Character::equip(AMateria *m) {
	for (int i = 0 ; i < 4 ; i++) {
		if (!slot_[i]) {
			slot_[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		return ;
	}
	slot_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3 || !slot_[idx])
		return ;
	slot_[idx]->use(target);
}

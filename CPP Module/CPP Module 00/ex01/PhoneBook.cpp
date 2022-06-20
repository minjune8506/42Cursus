#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
	this->size = 0;
}

void PhoneBook::add(Contact contact) {
	contacts[size % 8] = contact;
	size++;
}

void PhoneBook::printColumn(std::string column) {
	std::cout << std::setw(10);
	if (column.length() >= 10) {
		std::cout << column.substr(0, 9) + '.' << '|';
	} else {
		std::cout << column << '|';
	}
}

void PhoneBook::display() {
	std::cout << std::setw(10) << "index" << '|';
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname" << '|' << std::endl;
	for (int i = 0 ; i < size % 8; i++)
	{
		std::cout << std::setw(10) << i << '|';
		printColumn(contacts[i].getFirstName());
		printColumn(contacts[i].getLastName());
		printColumn(contacts[i].getNickName());
		std::cout << std::endl;
	}
}

void PhoneBook::searchContact(int index) {
	std::cout << "First Name : " << this->contacts[index].getFirstName() << '\n';
	std::cout << "Last Name : " << this->contacts[index].getLastName() << '\n';
	std::cout << "Nick Name : " << this->contacts[index].getNickName() << '\n';
	std::cout << "Phone Number : " << this->contacts[index].getPhoneNumber() << '\n';
	std::cout << "Darkest Secret : " << this->contacts[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getSize() {
	return this->size;
}

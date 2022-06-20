#include <iostream>
#include <limits>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void inputErrorHandling() {
	if (std::cin.fail() || std::cin.eof()) {
		std::cout << "Bad Input" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void add(PhoneBook &phoneBook) {
	Contact contact;

	contact.setFirstName();
	inputErrorHandling();
	contact.setLastName();
	inputErrorHandling();
	contact.setNickName();
	inputErrorHandling();
	contact.setPhoneNumber();
	inputErrorHandling();
	contact.setDarkestSecret();
	inputErrorHandling();
	phoneBook.add(contact);
}

void search(PhoneBook &phoneBook) {
	int index;

	phoneBook.display();
	std::cout << "Choose the index : ";
	std::cin >> index;
	inputErrorHandling();
	std::cin.ignore();
	if (index < 0 || index >= phoneBook.getSize()) {
		std::cout << "Index out of range!" << std::endl;
		return ;
	}
	phoneBook.searchContact(index);
}

int main(void) {
	std::string cmd;
	PhoneBook phoneBook;

	while (true) {
		std::cout << "Enter the command : ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD") {
			add(phoneBook);
		} else if (cmd == "SEARCH") {
			search(phoneBook);
		} else if (cmd == "EXIT") {
			break ;
		}
		if (std::cin.eof()) {
			break ;
		}
		if (std::cin.fail()) {
			std::cout << "Input Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

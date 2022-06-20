#include "Contact.hpp"
#include <iostream>

void Contact::setFirstName() {
	std::string firstName;

	std::cout << "First Name : ";
	std::getline(std::cin, firstName);
	this->firstName = firstName;
}

void Contact::setLastName() {
	std::string lastName;

	std::cout << "Last Name : ";
	std::getline(std::cin, lastName);
	this->lastName = lastName;
}

void Contact::setNickName() {
	std::string nickName;

	std::cout << "Nick Name : ";
	std::getline(std::cin, nickName);
	this->nickName = nickName;
}

void Contact::setPhoneNumber() {
	std::string phoneNumber;

	std::cout << "Phone number : ";
	std::getline(std::cin, phoneNumber);
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret() {
	std::string secret;

	std::cout << "Darkest Secret : ";
	std::getline(std::cin, secret);
	this->darkestSecret = secret;
}

std::string Contact::getFirstName() {
	return this->firstName;
}

std::string Contact::getLastName() {
	return this->lastName;
}

std::string Contact::getNickName() {
	return this->nickName;
}

std::string Contact::getPhoneNumber() {
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret() {
	return this->darkestSecret;
}

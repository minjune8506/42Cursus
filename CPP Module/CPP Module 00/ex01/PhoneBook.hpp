#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	void	add(Contact contact);
	void	printColumn(std::string column);
	void	display();
	void	searchContact(int index);
	int		getSize();

private:
	Contact	contacts[8];
	int		size;
};
#endif

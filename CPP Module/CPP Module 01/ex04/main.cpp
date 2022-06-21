#include <string>
#include <fstream> // file stream
#include <iostream>

int checkArgument(int ac) {
	if (ac != 4) {
		std::cout << "Argument Error" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int openFile(std::ifstream &ifs, std::ofstream &ofs, std::string fileName) {
	ifs.open(fileName);
	if (ifs.fail()) {
		std::cout << "Ifstream Open Failed" << std::endl;
		ifs.close();
		return (EXIT_FAILURE);
	}
	ofs.open(fileName + ".replace");
	if (ofs.fail()) {
		std::cout << "Ofstream Open Failed" << std::endl;
		ofs.close();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	std::string s1, s2, fileName;
	std::ifstream readFile;
	std::ofstream writeFile;
	std::string buffer;

	if (checkArgument(ac))
		return (EXIT_FAILURE);
	fileName = av[1];
	s1 = av[2];
	s2 = av[3];
	if (openFile(readFile, writeFile, fileName))
		return (EXIT_FAILURE);
	while (!readFile.eof()) {
		std::getline(readFile, buffer, '.');
		if (readFile.fail()) {
			std::cout << "Read Error" << std::endl;
			break ;
		}
		std::size_t found = buffer.find(s1);
		while (found != std::string::npos) {
			buffer.erase(found, s1.size());
			buffer.insert(found, s2);
			found = buffer.find(s1, found + s2.length());
		}
		writeFile << buffer << std::endl;
	}
	readFile.close();
	writeFile.close();
	return (EXIT_SUCCESS);
}
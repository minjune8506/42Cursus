#include <iostream>

class A {
public:
	A(std::string name) {
		this->name = name;
	}
	~A() {
		std::cout << "Destructor Called : " << name << std::endl;
	}
private:
	std::string name;
};

int main(void) {
	A *a = new A("A");
	A *b = new A("B");
	A c("C");

	delete a;
	return (0);
}